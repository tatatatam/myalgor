/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package np2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Athip
 */
public class NP2 {

    /**
     * @param args the command line arguments
     */
    private static int n = 5;
    private static int[][] adj;
    private static ArrayList<Integer> answer;

    public static void main(String[] args) {
        //credit: implement from https://www.cp.eng.chula.ac.th/~somchai/ULearn/Algorithms/

        //----------> approximation algorithm <----------
        //read file O(n^2)
        //vertex cover O(n^3)
        readfile();
        answer = new ArrayList<Integer>();
        vertexCover();
    }

    private static void readfile() {
        File file = new File("algor10q2-1.txt");
        try {
            Scanner input = new Scanner(file);
            adj = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adj[i][j] = input.nextInt();
                }
            }
        } catch (FileNotFoundException e) {
            System.err.println(e);
        }
    }

    private static void vertexCover() {

        //count degree of vertex
        int[] degree = new int[n];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (adj[i][j] == 1) {
                    cnt++;
                }
            }
            degree[i] = cnt;
        }

        //find vertex cover
        for (int run = 0; run < n; run++) {

            //find max degree
            cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (adj[i][j] == 1) {
                        cnt++;
                    }
                }
                degree[i] = cnt;
            }
            int max = 0;
            for (int x = 0; x < n; x++) {
                if (degree[max] < degree[x]) {
                    max = x;
                }
            }
            //degree[max] = 0; //delete max degree point

            //find vertex cover from max degree point
            for (int i = 0; i < n; i++) {
                if (adj[max][i] == 1) {
                    answer.add(i + 1);
                    //answer.add(max + 1);
                    for (int k = 0; k < n; k++) {
                        adj[i][k] = 0;
                        adj[k][i] = 0;
                    }
                }
            }
        }

        //selection sort
        for (int i = 0; i < answer.size(); i++) {

            for (int j = i; j < answer.size(); j++) {
                if (answer.get(j) < answer.get(i)) {
                    int temp = answer.get(i);
                    answer.set(i, answer.get(j));
                    answer.set(j, temp);
                }
            }
        }

        //output print
        for (int k = 0; k < answer.size(); k++) {
            System.out.print(answer.get(k) + " ");
        }
        System.out.println("");
        System.out.println(answer.size());
    }
}
