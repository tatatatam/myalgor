
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class greed{


    static String[][] time;
    static int people;

    public static void main(String[] args) {

        Scanner input=new Scanner(System.in);

        people=input.nextInt();

        System.out.print("Enter the number of time: ");
        System.out.println();
        time =new String[people][7];

            for(int i=0;i<time.length;i++){
            time[i][6]="0";
        }

        for (int i = 0; i < people; i++) {

            time[i][0] = input.next();
            time[i][1] = input.next();
            time[i][2] = input.next();

        }
        System.out.println("Output ");

        for (int i = 0; i < time.length; i++) {
            System.out.println(time[i][0] + " " + time[i][1] + " " + time[i][2]);

            System.out.println("mins: " + caltime(i));
        }



        printA();


//
        quicksort(time,0,time.length-1);

        for(int i=0;i<time.length;i++){
            time[i][6]="0";
        }
        printA();
        planning(time);
//        printA();

    }



    public static int caltime(int i){
       String time1=time[i][1];
       String[] start = time1.split(":");
        int hour1=Integer.parseInt(start[0]);
        int min1=Integer.parseInt(start[1]);

        String time2=time[i][2];
      String[] finish= time2.split(":");
        int hour2=Integer.parseInt(finish[0]);
        int min2=Integer.parseInt(finish[1]);
        int mins=0;
            if(hour2>=hour1)
                if(min2>=min1)
                  mins=(hour2-hour1)*60+(min2-min1);
                else if(min2<min1)
                  mins=((hour2-1)-hour1)*60+((min2+60)-min1);

            time[i][5] = Integer.toString(hour2 * 60 + min2);
            time[i][4] = Integer.toString(hour1 * 60 + min1);
            time[i][3] =Integer.toString(mins);

            return mins;

}

    public static void quicksort(String[][] arr,int low,int high){
        if(arr==null||arr.length==0)
            return;
        if(low>=high)
        return;

        int pivot = Integer.parseInt(time[low][5]);

        int i=low,j=high;
        while(i<=j){
            while(Integer.parseInt(arr[i][5]) < pivot){
                i++;
            }
            while(Integer.parseInt(arr[j][5]) > pivot){
                j--;
            }
            if(i<=j){
            String[][] tmp = new String[people][6];
            tmp[1] = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp[1];
                i++;
                j--;
            }
        }
        if(low<j)
            quicksort(arr,low,j);
        if(high>i)
            quicksort(arr,i,high);

    }

     public static void printA() {
        for (int a = 0; a < time.length; a++) {
            System.out.println(Arrays.toString(time[a]) + " ");
        }
        System.out.print("\n");
    }


    public static  void planning(String[][] time){
        ArrayList plan=new ArrayList();
        String[][] path=new String[people][10];
        ArrayList day=new ArrayList();

       int j=0;
       int days=0;
       int trigger=0;
	   int k=0;
	   int max = time.length;
	//    String[][] days = new String[max][max] ;

        // plan.add(time[0][0]);
        path[0]=time[0];
		// time[0][6] = "1";
		// time[0][4]="1";
		// time[0][5]="1";
		System.out.println(time[0][1]+" "+time[0][2]);

        while(trigger==0){
        for (int i = 1; i < time.length; i++) {
			// System.out.println("loopcount"+k);
			// System.out.println(time[i][1]+"asd"+time[j][1]+"");
	    	if (Integer.parseInt(time[i][4]) >= Integer.parseInt(time[j][5])){
				if(!(time[i][6].equals("1"))||!(time[j][6].equals("1"))){
						System.out.println(time[i][1]+"-"+time[i][2]+"");
	                path[j]=time[i];
					time[j][4]="1"; // i don't  know it need for this code just try
					time[j][5]="1";// is sime in line 148
	                // plan.add(time[i][0]);
	                time[j][6]="1";
	                j=i;
				}
			else{
				// System.out.println(time[i][1]+" insideS"+time[i][2]);
                k++;
                j=i;
            }
		}

	// System.out.println();

			if(k==max){ // trigger be max will out from loop
				trigger=1;
			}
			if(i+1==max){// if you re on last pick will be chosen
				// System.out.println(time[i][1]+" "+time[i][2]+"dd");
				time[j][6]="1";
				time[j][4]="1";
				time[j][5]="1";
			}
        }
		System.out.println("dday");
		j=0;

        // day.add(time[j][0]);
        // j++;

       }



            // System.out.println("\nThis is your plan: ");
//         for (int i = 0; i < plan.size(); i++) {
// //
//             System.out.print(path[i][0]);
//             System.out.println(day);
// //
//             if(i!=plan.size()-1) System.out.print("->");
//
//
//         }
        // System.out.println("");
        // System.out.println("Total girls you gonna date with: "+plan.size());

    }


//    public static  void planning(String[][] oak){
//        ArrayList plan=new ArrayList();
//        String[][] path=new String[people][6];
//
//        int j=0;
//
//        plan.add(oak[0][0]);
//        path[0]=oak[0];
////       //
//        for (int i = 1; i < oak.length; i++) {
//            //System.out.println("Next: "+A[i][4]+" Previous: "+A[i-1][5]);
//
//            if (Integer.parseInt(oak[i][4]) >= Integer.parseInt(path[j][5])){
//                //System.out.println("Add: "+A[i][0]);
//                j++;
//                path[j]=oak[i];
//                plan.add(oak[i][0]);
//
//            }
//        }
//
//            System.out.println("\nThis is your plan: ");
//        for (int i = 0; i < plan.size(); i++) {
//            //System.out.print(path.get(i));
//            System.out.print(path[i][0]);
//            if(i!=plan.size()-1) System.out.print("->");
//
//        }
//        System.out.println("");
//        System.out.println("Total girls you gonna date with: "+plan.size());
//
//



    }
//}
