/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab10_1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author HoundAZ
 */
public class LAB10_1 {

    /**
     * @param args the command line arguments
     */
    static boolean found = true;
    static int eye_count1 = 0;
    static int eye_count2 = 0;
    static String ans = null;
    static StringBuilder sr = new StringBuilder();

    public static void main(String[] args) {

//input text file        
        String path = "C:\\Users\\HoundAZ\\Documents\\Algor\\LAB10_1\\src\\lab10_1\\input.txt";

        File file = new File(path);
        int k = 0;
        int count = 0;
        String everything = null;

        try {
            StringBuilder sb = new StringBuilder();
            BufferedReader br = new BufferedReader(new FileReader(file));
            String line = br.readLine();

            while (line != null) {
                count++;
                sb.append(line);
                sb.append(System.lineSeparator());
                line = br.readLine();
            }
            everything = sb.toString();

            br.close();

        } catch (IOException e) {

            e.printStackTrace();

        }
        //--------------------------------------------------------------------//

//put data in array(number)
        int n = count - 1;
        int l, i, j;
        int[][] number = new int[n][n];
        String[] lines = everything.split("\\r?\\n");
        k = Integer.parseInt(lines[0]);
        System.out.println(k);
        for (l = 1, i = 0; l < lines.length; l++, i++) {
            j = 0;
            for (String token : lines[l].split("\\s+")) {
                number[j++][i] = Integer.parseInt(token);

            }

        }
        for (int mm = 0; mm < n; mm++) {
            for (int mn = 0; mn < n; mn++) {
                System.out.print(number[mm][mn] + " ");
            }
            System.out.println("");
        }
        //--------------------------------------------------------------------//

        int[] arr = new int[n];
        int[] data = new int[k];
        for (i = 0; i < n; i++) {

            arr[i] = i + 1;
        }

        combinationUtil(arr, data, 0, n - 1, 0, k, number);
//check is ans contain any number and print
        ans = sr.toString();
       
        if (eye_count1>0) {
            System.out.println("Yes");
            System.out.println(ans);
            

        } else {
            System.out.println("No");
        }

    }

    public static void combinationUtil(int arr[], int data[], int start, int end, int index, int k, int number[][]) {//n^2 *n!/n-r!r!
        int[] combi = new int[k];

//Combination part1
        if (index == k) {
            for (int j = 0; j < k; j++) {

                combi[j] = data[j];
            }

//create new array and put number data in
            int[][] adj = new int[number.length][number.length];

            for (int l = 0; l < adj.length; l++) {
                for (int m = 0; m < adj.length; m++) {
                    adj[l][m] = number[l][m];
                }

            }
//Compare
            for (int l = 0; l < k; l++) {
                for (int m = 0; m < adj.length; m++) {
                    if (adj[combi[l] - 1][m] != 0) {
                        adj[combi[l] - 1][m] = 0;
                        adj[m][combi[l] - 1] = 0;
                    }
                }
            }

//Check Table
            boolean cc = true;
            for (int l = 0; l < adj.length; l++) {
                for (int m = 0; m < adj.length; m++) {
                    if (adj[l][m] != 0) {
                        cc = false;
                    }
                }
            }
//use string builder to set in output data
            if (cc) {
                for (int j = 0; j < k; j++) {

                    sr.append(combi[j]);
                    sr.append(" ");
                }
                sr.append("\n");
                eye_count1++;
            } 

            return;
        }
//Combination part2
        for (int i = start; i <= end && end - i + 1 >= k - index; i++) {
            data[index] = arr[i];
            combinationUtil(arr, data, i + 1, end, index + 1, k, number);
        }

    }

}
