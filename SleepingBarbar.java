

//package threading.practice;

import java.util.Date;

import java.util.LinkedList;

import java.util.List;
import java.awt.*;

import java.util.concurrent.TimeUnit;

class SleepingBarber  {
    static String data="";
     Frame fr=new Frame("sleeping barbar");
    TextArea ta=new TextArea(data,25,100);
    Label l=new Label("resource occupied by");
    SleepingBarber()
    {
   fr.setLayout(new FlowLayout());
   fr.add(l);
    fr.add(ta);
    fr.setSize(900,900);
    fr.setVisible(true);
     }

    public static void main(String a[])

    {
  //  SleepingBarber sb=new SleepingBarber();

        Bshop shop = new Bshop();

        Barber barber = new Barber(shop);

        CustomerGenerator cg = new CustomerGenerator(shop);

        Thread thbarber = new Thread(barber);

        Thread thcg = new Thread(cg);

        thcg.start();

        thbarber.start();
        //sb.func();

    }
   /* void func()
    {
ta=new TextArea(data);
    }
*/
}

class Barber extends SleepingBarber implements Runnable

{

    Bshop shop;

    public Barber(Bshop shop)

    {

        this.shop = shop;

    }

    public void run()

    {

        try

        {

            Thread.sleep(10000);

        }

        catch(InterruptedException iex)

        {

            iex.printStackTrace();

        }

        //System.out.println("Barber started..");
        data=data+"barber started..\n";

        while(true)

        {

            shop.cutHair();

        }

    }

}

class Customer extends SleepingBarber implements Runnable

{

    String name;

    Date inTime;

    Bshop shop;

    public Customer(Bshop shop)

    {

        this.shop = shop;

    }

    public String getName() {

        return name;

    }

    public Date getInTime() {

        return inTime;

    }

    public void setName(String name) {

        this.name = name;

    }

    public void setInTime(Date inTime) {

        this.inTime = inTime;

    }

    public void run()

    {

        goForHairCut();

    }

    private synchronized void goForHairCut()

    {

        shop.add(this);

    }

}

class CustomerGenerator extends SleepingBarber implements Runnable

{

    Bshop shop;

    public CustomerGenerator(Bshop shop)

    {

        this.shop = shop;

    }

    public void run()

    {

        while(true)

        {

            Customer customer = new Customer(shop);

            customer.setInTime(new Date());

            Thread thcustomer = new Thread(customer);

            customer.setName("Customer Thread "+thcustomer.getId());

            thcustomer.start();

            try

            {

                TimeUnit.SECONDS.sleep((long)(Math.random()*10));

            }

            catch(InterruptedException iex)

            {

                iex.printStackTrace();

            }

        }

    }

}

class Bshop extends SleepingBarber

{

    int nchair;

    List<Customer> listCustomer;

    public Bshop()

    {

        nchair = 3;

        listCustomer = new LinkedList<Customer>();

    }

    public void cutHair()

    {

        Customer customer;

       // System.out.println("Barber waiting for lock.");
data=data+"barber waiting for lock..\n";
        synchronized (listCustomer)

        {

            while(listCustomer.size()==0)

            {

                //System.out.println("Barber is waiting for customer.");
                ta.append("barber is waiting for customer..\n");

                try

                {

                    listCustomer.wait();

                }

                catch(InterruptedException iex)

                {

                    iex.printStackTrace();

                }

            }

            //System.out.println("Barber found a customer in the queue.");
            data=data+"barber found  a customer in the queue..\n ";

            customer = (Customer)((LinkedList<?>)listCustomer).poll();

        }

        long duration=0;

        try

        {    

            //System.out.println("Cuting hair of Customer : "+customer.getName());
            data=data+"cutting hair of customer:"+customer.getName()+"\n";

            duration = (long)(Math.random()*10);

            TimeUnit.SECONDS.sleep(duration);

        }

        catch(InterruptedException iex)

        {

            iex.printStackTrace();

        }

        data=data+"Completed Cuting hair of Customer : "+customer.getName() + " in "+duration+ " seconds.";

    }

    public void add(Customer customer) 

    {

        data+="Customer : "+customer.getName()+ " entering the shop at "+customer.getInTime();

        synchronized (listCustomer)

        {

            if(listCustomer.size() == nchair)

            {

                data+="No chair available for customer "+customer.getName();

                data+="Customer "+customer.getName()+"Exists...";

                return ;

            }

            ((LinkedList<Customer>)listCustomer).offer(customer);

            data+="Customer : "+customer.getName()+ " got the chair.";

             

            if(listCustomer.size()==1)

                listCustomer.notify();

        }

    }

}

