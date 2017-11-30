/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Athip
 */
public class NP3 {

    /**
     * @param args the command line arguments
     */
    private static int m; //number of clauses
    private static int n, K, k; //number of variables(type: 1,-1,2,-2 is 2 type)
    private static ArrayList<Integer> keep_triAngle = new ArrayList<>();
    private static ArrayList<Integer> keep_type = new ArrayList<>();
    private static int[][] answer;

    public static void main(String[] args) {
        readfile();

        // set type of all variable
        setType();

        vertexCover();
        printAns();

    }

    private static void readfile() {
        String path = "./m2ii.txt";
        File file = new File(path);
        String[] tmpArr;
        try {
            Scanner input = new Scanner(file);

            // read number of clause
            m = input.nextInt();

            // skip line
            input.nextLine();

            for (int i = 0; i < m; i++) {
                tmpArr = input.nextLine().split(" ");
                for (String s : tmpArr) {
                    keep_triAngle.add(Integer.parseInt(s));
                }
            }
              System.out.print(keep_triAngle+"\n");
        } catch (FileNotFoundException e) {
            System.err.println(e);
        }
    }


    private static void vertexCover() {
        n = keep_type.size() / 2;  //n is number of type
        K = 2 * n + 3 * m;  //K is number of vertex
        k = n + 2 * m;   //k is number of cover vertex for check satisfy

        // create array 2D for keep Graph
        answer = new int[K][K];


        for (int i = 0; i < 2 * n; i += 2) { // i will scan index of keep_type
            addEdge(i, i + 1);
        }


        for (int i = 0; i < 3 * m; i++) { // i will scan index of keep_triAngle which size = 3m

            if (i % 3 == 0) {
                addEdge((2 * n) + i, (2 * n) + i + 1);
                addEdge((2 * n) + i, (2 * n) + i + 2);
            } else if (i % 3 == 1) {
                addEdge((2 * n) + i, (2 * n) + i + 1);
            }

            for (int j = 0; j < keep_type.size(); j++) { // j will scan index of keep_type which size = 2n
                // i will stand, but j walk
                if (keep_triAngle.get(i) == keep_type.get(j)) {
                    addEdge(j, (2 * n) + i);
                }
            }
        }
    }


    private static void setType() {
        for (Integer n : keep_triAngle) {
            if (!keep_type.contains(n)) {
                keep_type.add(Math.abs(n));
                keep_type.add(Math.abs(n) * -1);
            }
        }
          System.out.print(keep_type+"\n");
    }

    private static void addEdge(int i1, int i2) {
        answer[i1][i2] = 1;
        answer[i2][i1] = 1;
    }

    private static void printAns() {
        int size = answer.length;
        System.out.println(K);
        System.out.println(k);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < answer.length; j++) {
                System.out.printf("%d ", answer[i][j]);
            }
            System.out.println("");
        }
    }
}
