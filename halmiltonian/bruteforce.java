import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class BruteForce {
	public int records;
	ArrayList<CrimeNode> listOfCrimes = new ArrayList<CrimeNode>();
	public double[][] distances;
	ArrayList<CrimeNode> orderedList;

	ArrayList<CrimeNode> path = new ArrayList<CrimeNode>();
	double bestDistance;
	//X,Y,Time,Street,Offense,Date,Tract,Lat,Long

	public BruteForce(String crimeDataLocation, int max){
		String nextLine = "";
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(crimeDataLocation));
			br.readLine();
			this.records = 0;
			this.bestDistance = Double.MAX_VALUE;
			//add the data to an array and then insert each element of the array into the tree
			while ((nextLine = br.readLine()) != null && records <= max) {
				records ++;
				String[] variables = nextLine.split(",");
				this.insert(variables[0],variables[1],variables[2],variables[3],variables[4],variables[5],variables[6],variables[7],variables[8]);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

    public void doBruteForce(int begin, int finish){
    	ArrayList<Integer> list = new ArrayList<Integer>();
    	//make an array list with all of the necessary nodes represented as their index in the listOfCrimes
    	for (int i = begin; i <= finish; i++){
    		list.add(i);
    	}
    	//do the recursive brute force permutations
    	bruteForce(new ArrayList<Integer>(), list);
    	//print the data to the console
    	for (CrimeNode n : path){
    		n.print();
    	}
    	System.out.print("Hamiltonian Cycle: ");
    	for (CrimeNode n : path){
    		System.out.print((listOfCrimes.indexOf(n) - begin) + ", ");
    	}
    	System.out.println("");
    	System.out.println("Length of Cycle: " + this.bestDistance*0.00018939);
    }

	public double distanceOfPath(ArrayList<CrimeNode> list){
		//for each element in the list, compute the distance from that element to the next one.
		double distance = 0;
		for (int i = 0; i < list.size() - 1; i++){
			distance += this.distanceBetweenNodes(list.get(i), list.get(i+1));
		}
		//return the total length of the path
		return distance;
	}

	public void bruteForce(ArrayList<Integer> holder, ArrayList<Integer> list){
		//if the list isnt empty
        if (!list.isEmpty()){
        	//for each element
            for (int i = 0; i < list.size(); i++){
            	//copy the both array lists to new lists
       			ArrayList<Integer> newholder = new ArrayList<Integer>();
       			for (Integer a : holder){
       				newholder.add(a);
       			}
       			ArrayList<Integer> newList = new ArrayList<Integer>();
       			for (Integer b : list){
       				newList.add(b);
       			}
       			//then move on element to the other list
            	holder.add(list.get(i));
            	list.remove(i);
            	//and recursively brute force
            	this.bruteForce(holder, list);
            	//after the recursive splitting returns, the loop will restart and move a different element
            	//so make sure the arrayLists are the same as when the loop began
       			holder = new ArrayList<Integer>();
       			for (Integer a : newholder){
       				holder.add(a);
       			}
       			list = new ArrayList<Integer>();
       			for (Integer b : newList){
       				list.add(b);
       			}
            }
   		} else {
   			//the list is empty, so check the arraylist holding the final elements
        	holder.add(holder.get(0));
        	ArrayList<CrimeNode> holderCrimes = new ArrayList<CrimeNode>();
        	for (Integer i:holder){
        		holderCrimes.add(this.listOfCrimes.get(i));
        	}
        	//if the current permutation is the shortest one, save it
        	if (distanceOfPath(holderCrimes) < this.bestDistance){
        		this.bestDistance = distanceOfPath(holderCrimes);
        		this.path = holderCrimes;
        	}
        }
    }

	public void insert(String x, String y, String time, String street, String offense, String date, String tract, String lat, String lon){
		CrimeNode curNode = new CrimeNode(x,y,time,street,offense,date,tract,lat,lon);
		listOfCrimes.add(curNode);
	}

	public double distanceBetweenNodes(CrimeNode n1, CrimeNode n2){
		return pythag(n1.x, n1.y, n2.x, n2.y);
	}

	public double pythag(double x1, double y1, double x2, double y2){
		//gets distance between two points with the Pythagorean theorem
		double x = Math.pow((x2-x1),2);
		double y = Math.pow((y2-y1),2);
		return Math.pow((x+y), 0.5);
	}

	public void findAllWeights(ArrayList<CrimeNode> graph){
		this.distances = new double[records][records];
		for (CrimeNode baseNode : graph){
			for (CrimeNode otherNode : graph){
				this.distances[graph.indexOf(baseNode)][graph.indexOf(otherNode)] = distanceBetweenNodes(baseNode, otherNode);
			}
		}
	}

	public void printDistanceArray(){
		for (int i=0; i<this.distances.length; i++){
			for (int j=0; j<this.distances[0].length; j++){
				System.out.print(this.distances[i][j] + " ; ");
			}
			System.out.println(" ");
		}
	}
}
