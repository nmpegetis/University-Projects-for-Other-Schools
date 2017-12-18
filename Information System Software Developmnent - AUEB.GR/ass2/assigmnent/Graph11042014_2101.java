import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;


public class Graph {
    private static LinkedList<Integer> llist;
//public class Graph implements Comparator<HashMap<Integer, Integer>> {
//	public int compare(Integer x, Integer y) {
//        return Integer.valueOf(x).compareTo(y);
//    }
//	/**
//	 * @param args
//	 */
//	@Override
//	public int compare(HashMap<Integer, Integer> arg0,
//			HashMap<Integer, Integer> arg1) {
//		// TODO Auto-generated method stub
//		if (arg0.values().iterator().next() > arg1.values().iterator().next())
//			return 1;
//		else if (arg0.values().iterator().next() < arg1.values().iterator().next())			
//			return -1;
//		return 0;
//	}


    private static void addValue(int val) {
        if (llist.size() == 0) {
            llist.add(val);
        } else if (llist.get(0) > val) {
            llist.add(0, val);
        } else if (llist.get(llist.size() - 1) < val) {
            llist.add(llist.size(), val);
        } else {
            int i = 0;
            while (llist.get(i) < val) {
                i++;
            }
            llist.add(i, val);
        }
    }
	
	/**
	 * @param graph
	 * @param weightedEdges
	 * @param s
	 * @return dijkstraResult
	 */
	public ArrayList<ArrayList<Integer>> dijkstraAlgorithm (HashMap<Integer, ArrayList<Integer>> graph, HashMap<Integer,HashMap<Integer,Integer>> weightedEdges, Integer s) {
/**		Input: G = (V,E,s), a graph and a starting node s
		Output: (pred,dist): pred is an array of size |V| such that pred[i] is the
				predecessor of node i in the shortest path from s; dist is an array of
				size |V| such that dist[i] is the length of the shortest path calculated
				from node s to i
		Data: pq, a priority queue of nodes that prioritises by the path length to a
				node
*/		
		ArrayList<ArrayList<Integer>> dijkstraResult = new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> dist = new ArrayList<Integer>();
		ArrayList<Integer> pred = new ArrayList<Integer>();	
		
		Queue<Integer> pq = new PriorityQueue<Integer>();
		
		Integer u;
		
//		System.out.println("Graph Nodes are: "+graph.keySet());
		for (Integer v : graph.keySet()){
			pred.add(v, -1);
			if (v != s){				
				dist.add(v,Integer.MAX_VALUE);
			}
			else{
				dist.add(v,0);				
			}
			pq.offer(dist.get(v));					// equal to presantation's algorithm "Insert(pq,v,dist[v])", inserts v in the queue pq and the value of v is stored in the 'dist' arrayList			
		}

		while (pq.size() != 0){
			u = dist.indexOf(pq.poll());				// retrieves and removes the first item from the queue, sorted by dist value
			//	System.out.println("\nu="+u+"      pq size="+pq.size());
			if(u>=0){
				System.out.println("\nu="+u);
				System.out.println("\npred ("+u+")= "+pred.get(u));
				for (Integer v : graph.get(u)) {				//representation of adjacency list
				//	System.out.println("dist("+v+")="+dist.get(v)+" > dist(u)="+dist.get(u)+" + w="+weightedEdges.get(u).get(v)+" ??");
					if (v!=u){
						if (dist.get(v) > Math.abs(dist.get(u)+weightedEdges.get(u).get(v))){
							dist.set(v, dist.get(u)+weightedEdges.get(u).get(v));
							System.out.println("NEW dist("+v+")="+dist.get(v));
							if (v!=u)
								pred.set(v, u);
							pq.offer(dist.get(v));		// equal to presantation's algorithm "Insert(pq,v,dist[v])", inserts v in the queue pq and the value of v is stored in the 'dist' arrayList			
						}
					}
				}
			}
		}

		dijkstraResult.add(pred);
		dijkstraResult.add(dist);

		return dijkstraResult;
	}
	

	
	
	/**
	 * @param graph
	 * @param weightedEdges
	 * @param s
	 * @return shortestPathsResult
	 */
	public ArrayList<int[][]> shortestPathAlgorithm (HashMap<Integer, ArrayList<Integer>> graph, HashMap<Integer,HashMap<Integer,Integer>> weightedEdges, Integer s) {
	/**	Input: G = (V,E), a graph and a starting node s
		Output: (pred,dist): pred is an array of size |V| X |V| such that pred[i][j] is
			the predecessor of node j in the shortest path from i to j; dist is an
			array of size |V| X |V| such that dist[i][j] is the length of the
			shortest path calculated from node i to j
	 */		
		ArrayList<int[][]> shortestPathsResult = new ArrayList<int[][]>();
		ArrayList<ArrayList<Integer>> dijkstraResult = new ArrayList<ArrayList<Integer>>();
		int[][] dist = new int[graph.size()][graph.size()];
		int[][] pred = new int[graph.size()][graph.size()];	
		


		for (Integer u : graph.keySet()){
			for (Integer v : graph.keySet()){
				pred[u][v] = -1;
				dist[u][v] = 0;
			}
		}
		
		for (Integer u : graph.keySet()){
			System.out.println("\n*************************\n* Starting Node is : "+u+" *\n*************************");
			dijkstraResult = dijkstraAlgorithm(graph, weightedEdges, u);
			for (int i=0 ; i<dijkstraResult.size() ; i++){
				for (int j=0 ; j<dijkstraResult.get(i).size() ; j++){
					if (i==0)
						pred[u][j] = dijkstraResult.get(i).get(j);
					else
						dist[u][j] = dijkstraResult.get(i).get(j);
				}
			}	
		}
		
		shortestPathsResult.add(pred);
		shortestPathsResult.add(dist);

		return shortestPathsResult;
	}
	
	
	
	/**
	 * @param graph
	 * @param weightedEdges
	 * @param s
	 * @return diameter
	 */
	public int graphDiameterAlgorithm (HashMap<Integer, ArrayList<Integer>> graph, HashMap<Integer,HashMap<Integer,Integer>> weightedEdges, Integer s) {
	/**	Input: G = (V,E), a graph and a starting node s
		Output: diameter: the length of the	longest -- of the shortest paths calculated from node i to j --
	 */		
		ArrayList<ArrayList<Integer>> dijkstraResult = new ArrayList<ArrayList<Integer>>();
		int[][] dist = new int[graph.size()][graph.size()];
		int[][] pred = new int[graph.size()][graph.size()];	
		int diameter = 0;


		for (Integer u : graph.keySet()){
			for (Integer v : graph.keySet()){
				pred[u][v] = -1;
				dist[u][v] = 0;
			}
		}
		
		for (Integer u : graph.keySet()){
			System.out.println("\n*************************\n* Starting Node is : "+u+" *\n*************************");
			dijkstraResult = dijkstraAlgorithm(graph, weightedEdges, u);
			for (int i=0 ; i<dijkstraResult.size() ; i++){
				for (int j=0 ; j<dijkstraResult.get(i).size() ; j++){
					if (i==0)
						pred[u][j] = dijkstraResult.get(i).get(j);
					else
						dist[u][j] = dijkstraResult.get(i).get(j);
				}
				if (diameter < dijkstraResult.get(i).size())
					diameter = dijkstraResult.get(i).size();
			}	
		}
			
		return diameter;
	}
	
	

	public static void main(String[] args) throws IOException {
        
        llist = new LinkedList<Integer>();
        
        if (args.length >= 2 && args.length <= 6){ 
        	
	    	int argn = 0;				//counter for arguments
	    	int start = 0;
	    	boolean directed = true;
	    	String scan;
			Graph graph = new Graph();
			
			ArrayList<ArrayList<Integer>> dijkstraResult = new ArrayList<ArrayList<Integer>>();
			ArrayList<int[][]> shortestPathsResult = new ArrayList<int[][]>();
			int[][] resultDist;
			int[][] resultPred;
			Integer diameter = 0;
			
			Integer vertexFrom = null;
			Integer vertexTo = null;
			Integer weight = null;
			ArrayList<Integer> verticesTo = new ArrayList<Integer>();
			HashMap<Integer,Integer> edges = new HashMap<Integer,Integer>();
			HashMap<Integer, ArrayList<Integer>> graphDirected = new HashMap<Integer,ArrayList<Integer>>();
			HashMap<Integer, ArrayList<Integer>> graphUndirected = new HashMap<Integer,ArrayList<Integer>>();
			HashMap<Integer,HashMap<Integer,Integer>> weightedEdges = new HashMap<Integer,HashMap<Integer,Integer>>();
            String s[] = null;

			
			if (args[argn].trim().equals("-u")){
				directed = false;
				argn++;
			}
			if (args[argn].trim().equals("-s")){
				argn++;
				if ((start = Integer.valueOf(args[argn].trim())) >= 0){
					argn++;
				}
				else{
					System.err.println("Error in node typed in command. You typed node="+args[argn]+" and it must pe a zero or positive number. Try again...");						
					System.exit(1);
				}					
			}
			else if (args[argn].trim().equals("-a")){
				argn++;
			}
			else if (args[argn].trim().equals("-d")){
				argn++;
			}
			else {
				System.err.println("The first argument must be '-u', '-s', '-a' or '-d'. You typed something else. Try again...");
				System.exit(1);
			}
			
			
			FileReader file = new FileReader(args[argn]);
            BufferedReader br = new BufferedReader(file);

            if(!directed){								//if the first argument was '-u'
        		while((scan = br.readLine()) != null)
        		{
        		//	System.out.println(scan);	// in order to check if lines are read in a correct way
        			s = scan.split(" ");
        			vertexFrom = Integer.valueOf(s[0]);
        			vertexTo = Integer.valueOf(s[1]);
        			if (s.length==3)
        				weight = Integer.valueOf(s[2]);
        			else
        				weight = 1;
        				
        			if (graphUndirected.containsKey(vertexFrom)){	// if there is already the node in the graphMap the append the node's list of directions to next nodes
        				graphUndirected.get(vertexFrom).add(Integer.valueOf(s[1]));        				        			
        			}
        			else{								// otherwise create a new node node in the graphMap and set the node's list of directions to next nodes
            			verticesTo = new ArrayList<Integer>();	// remove the added value to be zero again for next use        				
            			verticesTo.add(Integer.valueOf(s[1]));        				
        				graphUndirected.put(vertexFrom, verticesTo);        				        				
        			}
        			
        			if (weightedEdges.containsKey(vertexFrom)){	// if there is already the node in the graphMap the append the node's list of directions to next nodes
        				weightedEdges.get(vertexFrom).put(vertexTo, weight);
        			}
        			else{
        				edges = new HashMap<Integer,Integer>();
        				edges.put(vertexTo,weight);
        				weightedEdges.put(vertexFrom, edges);            		
        			}
        		}
            }
        	else{        		
        		while((scan = br.readLine()) != null)
        		{
        			//	System.out.println(scan);	// in order to check if lines are read in a correct way
        			s = scan.split(" ");
        			vertexFrom = Integer.valueOf(s[0]);
        			vertexTo = Integer.valueOf(s[1]);
        			weight = Integer.valueOf(s[2]);
        			
        			if (graphDirected.containsKey(vertexFrom)){	// if there is already the node in the graphMap the append the node's list of directions to next nodes
        				graphDirected.get(vertexFrom).add(Integer.valueOf(s[1]));        				        			
        			}
        			else{								// otherwise create a new node node in the graphMap and set the node's list of directions to next nodes
            			verticesTo = new ArrayList<Integer>();	// remove the added value to be zero again for next use        				
            			verticesTo.add(Integer.valueOf(s[1]));        				
        				graphDirected.put(vertexFrom, verticesTo);        				        				
        			}
        			
        			if (weightedEdges.containsKey(vertexFrom)){	// if there is already the node in the graphMap the append the node's list of directions to next nodes
        				weightedEdges.get(vertexFrom).put(vertexTo, weight);
        			}
        			else{
        				edges = new HashMap<Integer,Integer>();
        				edges.put(vertexTo,weight);
        				weightedEdges.put(vertexFrom, edges);            		
        			}
        		}
        	}
            br.close();

            
// GRAPH PRINTINGS e.g. {0, [1 (10), 3 (5), ]} where 0 is the node, 1 and 3 are the nodes that node 1 is connected with, and 10 and 5 are the edge weight of (0,1) and (0,3) edges respectively
       	for (int i : graphDirected.keySet()){
            	System.out.print("\n{"+ i+", [");
            	for (int j : graphDirected.get(i)){
            		System.out.print(j+" ("+weightedEdges.get(i).get(j)+"), ");
            	}            	
            	System.out.println("]}");
            }
            
// FUNCTION CALLS 			
            argn = 0;
			if (args[argn].trim().equals("-u")){
				directed = false;
				argn++;
			}
			
			if (args[argn].trim().equals("-s")){
				argn++;
				if ((start = Integer.valueOf(args[argn].trim())) >= 0){
					if (directed)
						dijkstraResult = graph.dijkstraAlgorithm(graphDirected,weightedEdges,start);						
					else
						dijkstraResult = graph.dijkstraAlgorithm(graphUndirected,weightedEdges,start);						
					argn++;
				}
			}
			else if (args[argn].trim().equals("-a")){
				shortestPathsResult = graph.shortestPathAlgorithm(graphDirected,weightedEdges,start);						
			}
			else if (args[argn].trim().equals("-d")){
				diameter = graph.graphDiameterAlgorithm(graphDirected,weightedEdges,start);						
			}

			
			
// RESULTS PRINTING			
			if (args[argn].trim().equals("-a")){
				for (int i=0 ; i<shortestPathsResult.size() ; i++){
					if (i==0){
						System.out.println("\nPredecessor matrix");
						
						resultDist  = new int[shortestPathsResult.get(i).length][shortestPathsResult.get(i).length];
						for(int j=0 ; j<shortestPathsResult.get(i).length ; j++){
							resultDist[j] = shortestPathsResult.get(i)[j];

							System.out.print("[");
							
							for(int k=0 ; k<resultDist[j].length ; k++){
//								System.out.println("dist["+j+"]["+k+"] = "+resultDist[j][k]);
								System.out.print(resultDist[j][k]+", ");
								}						
							
							System.out.println("]");
						}

					}
					else{
						System.out.print("\nDistance matrix\n[");

						resultPred  = new int[shortestPathsResult.get(i).length][shortestPathsResult.get(i).length];
						for(int j=0 ; j<shortestPathsResult.get(i).length ; j++){
							resultPred[j] = shortestPathsResult.get(i)[j];

							System.out.print("[");

							for(int k=0 ; k<resultPred[j].length ; k++){
//								System.out.println("dist["+j+"]["+k+"] = "+resultPred[j][k]);
								System.out.print(resultPred[j][k]+", ");
						}						
							
							System.out.println("]");
						}
					}
				}
			}
			else if (args[argn].trim().equals("-d")){
				System.out.println("\nDiameter = "+diameter);
			}
			else{
				for (int i=0 ; i<dijkstraResult.size() ; i++){
					if (i==0)
						System.out.print("\nPredecessor matrix\n[");
					else
						System.out.print("\nDistance matrix\n[");

					for (int j=0 ; j<dijkstraResult.get(i).size() ; j++){
						if (i==0)
//							System.out.println("pred["+j+"] = "+dijkstraResult.get(i).get(j));
							System.out.print(dijkstraResult.get(i).get(j)+", ");
						else
//							System.out.println("dist["+j+"] = "+dijkstraResult.get(i).get(j));
							System.out.print(dijkstraResult.get(i).get(j)+", ");
					}
					if (i==0)
						System.out.println("]");
					else
						System.out.println("]");
				}	
			}     
		}
		else {			
			System.err.println("THIS PROGRAM WAS DEVELOPPED IN ECLIPSE. IT HAS 2-6 ARGUMENTS: [<TYPE_OF_DIRECTION>] <TYPE> [<STARTING NODE>] <CSV FILE> [<REDIRECTION_TO_FILE('>')>] [<OUTPUT FILE>]. EDIT IT FROM THE RUN CONFIGURATION");
			System.err.println("You haved typed a wrong number of arguments. You should type something like:\n '-u -s 0 traffic.txt' or \n '-u -s 0 traffic.txt > output.txt' in the Run Configuration of Eclipse. Try again...");
		}
	}
}

