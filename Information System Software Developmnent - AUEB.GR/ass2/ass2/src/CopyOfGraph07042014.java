import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.SortedSet;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

public class CopyOfGraph07042014 {

	
	/**
	 * @param args
	 */
	private HashMap<Vertex, TreeMap<Vertex,Integer>> myAdjList;
	private HashMap<String, Vertex> myVertices;
	private static final TreeSet<Vertex> EMPTY_SET = new TreeSet<Vertex>();
	private int myNumVertices;
	private int myNumEdges;

	/**
	 * Construct empty Graph
	 */
	public CopyOfGraph07042014() {
		myAdjList = new HashMap<Vertex, TreeMap<Vertex,Integer>>();
		myVertices = new HashMap<String, Vertex>();
		myNumVertices = myNumEdges = 0;

	}
	
	/**
	 * Add a new vertex name with no neighbors (if vertex does not yet exist)
	 * 
	 * @param name
	 *            vertex to be added
	 */
	public Vertex addVertex(String name) {
		Vertex v;
		v = myVertices.get(name);
		if (v == null) {
			v = new Vertex(name);
			myVertices.put(name, v);
			myAdjList.put(v, new TreeMap<Vertex,Integer>());
			myNumVertices += 1;
		}
		return v;
	}

	/**
	 * Returns the Vertex matching v
	 * @param name a String name of a Vertex that may be in
	 * this Graph
	 * @return the Vertex with a name that matches v or null
	 * if no such Vertex exists in this Graph
	 */
	public Vertex getVertex(String name) {
		return myVertices.get(name);
	}

	/**
	 * Returns true iff v is in this Graph, false otherwise
	 * @param name a String name of a Vertex that may be in
	 * this Graph
	 * @return true iff v is in this Graph
	 */
	public boolean hasVertex(String name) {
		return myVertices.containsKey(name);
	}

	/**
	 * Is from-to, an edge in this Graph. The graph is 
	 * undirected so the order of from and to does not
	 * matter.
	 * @param from the name of the first Vertex
	 * @param to the name of the second Vertex
	 * @return true iff from-to exists in this Graph
	 */
	public boolean hasEdge(String from, String to) {

		if (!hasVertex(from) || !hasVertex(to))
			return false;
		return myAdjList.get(myVertices.get(from)).containsKey(myVertices.get(to));
	}
	
	/**
	 * Add to to from's set of neighbors, and add from to to's
	 * set of neighbors. Does not add an edge if another edge
	 * already exists
	 * @param from the name of the first Vertex
	 * @param to the name of the second Vertex
	 */
	public void addEdge(String from, String to, int weight, boolean directed) {
		Vertex v, w;
		if (hasEdge(from, to))
			return;
		myNumEdges += 1;
		if ((v = getVertex(from)) == null)
			v = addVertex(from);
		if ((w = getVertex(to)) == null)
			w = addVertex(to);
		myAdjList.get(v).put(w,weight);
		if (!directed)
			myAdjList.get(w).put(v,weight);
	}

	/**
	 * Return an iterator over the neighbors of Vertex named v
	 * @param name the String name of a Vertex
	 * @return an Iterator over Vertices that are adjacent
	 * to the Vertex named v, empty set if v is not in graph
	 */
	public Iterable<Vertex> adjacentTo(String name) {
		if (!hasVertex(name))
			return EMPTY_SET;
		return myAdjList.get(getVertex(name)).keySet();
	}

	/**
	 * Return an iterator over the neighbors of Vertex v
	 * @param v the Vertex
	 * @return an Iterator over Vertices that are adjacent
	 * to the Vertex v, empty set if v is not in graph
	 */
	public Iterable<Vertex> adjacentTo(Vertex v) {
		if (!myAdjList.containsKey(v))
			return EMPTY_SET;
		return myAdjList.get(v).keySet();
	}

	/**
	 * Returns an Iterator over all Vertices in this Graph
	 * @return an Iterator over all Vertices in this Graph
	 */
	public Iterable<Vertex> getVertices() {
		return myVertices.values();
	}

	public int numVertices()
	{
		return myNumVertices;
	}
	
	public int numEdges()
	{
		return myNumEdges;
	}
	
	
	/*
	 * Returns adjacency-list representation of graph
	 */
	public String toString() {
		String s = "";
		for (Vertex v : myVertices.values()) {
			s += v + ": ";
			for (Vertex w : myAdjList.get(v).keySet()) {
				s += w + " ";
			}
			s += "\n";
			for (Integer d : myAdjList.get(v).values()) {
				s += d + " ";
			}
			s += "\n";

		}
		return s;
	}

	
	public Set dijkstraAlgorithm (Vertex start) {
/**		Input: G = (V,E,s), a graph and a starting node s
		Output: (pred,dist): pred is an array of size |V| such that pred[i] is the
				predecessor of node i in the shortest path from s; dist is an array of
				size |V| such that dist[i] is the length of the shortest path calculated
				from node s to i
		Data: pq, a priority queue of nodes that prioritises by the path length to a
				node
*/		
//		myAdjList;myVertices;myNumVertices;myNumEdges;

		HashMap<Vertex,Integer> dist = new HashMap<Vertex,Integer>();
		HashMap<Vertex,Vertex> pred = new HashMap<Vertex,Vertex>();
		Set set = new HashSet();
		
		Queue<Vertex> pq = new PriorityQueue<Vertex>();

		Vertex u = start;

		for (Vertex v : myVertices.values()){
			pred.put(v,new Vertex("-1"));
			if (!v.equals(start)){				
				dist.put(v, Integer.MAX_VALUE);
			}
			else{
				dist.put(v, 0);				
			}
			
			pq.add(v);					// equal to presantation's algorithm "Insert(pq,v,dist[v])", inserts v in the queue pq and the value of v is stored in the 'dist' arrayList
		}
		
		while (pq.size() != 0){
			u = pq.poll();				// retrieves and removes the first item from the queue, sorted by dist value
			for (Vertex v : myAdjList.keySet()) {				//representation of adjacency list
				if(dist.get(v) > dist.get(u) + myAdjList.get(v).get(u)){
					dist.put(v, dist.get(u) + myAdjList.get(v).get(u));
					pred.put(v, u);
					TreeMap<Vertex, Integer> tm = myAdjList.get(v);
					tm.put(v, dist.get(v));
					myAdjList.put(v, tm);
				}
					
			}
		}
		
		set.add(dist);
		set.add(pred);
		
		return set;
	}
	

	
	public ArrayList<String> shortestPathAlgorithm (ArrayList<Integer> vertexFrom, ArrayList<Integer> vertexTo) {
//		Input: vertexTo, an array with n stock price vertexTos
//		Output: span, an array with n stock price spans		
//		Data: s, a stack
		
		ArrayList<String> span = new ArrayList<String>();
		Stack<Integer> s = new Stack<Integer>();
		
		s.push(0);
		span.add(0, vertexFrom.get(0)+","+1);
		for (int i=1 ; i<vertexFrom.size() ; i++){
			while (!s.empty() && vertexTo.get(s.peek()) <= vertexTo.get(i)){
				s.pop();
			}	
			if (s.empty()){
				span.add(i, vertexFrom.get(i)+","+(i+1));
			}
			else{
				span.add(i, vertexFrom.get(i)+","+(i-s.peek()));
			}
			s.push(i);
		}
		
		return span;
	}
	
	
	public ArrayList<String> graphDiameterAlgorithm (ArrayList<Integer> vertexFrom, ArrayList<Integer> vertexTo) {

		return null;
	}
	
	
	public static void main(String[] args) throws IOException {
        
        if (args.length >= 2 && args.length <= 6){ 
        	
	    	int argn = 0;				//counter for arguments
	    	int lineCounter = 0;
	    	int start = 0;
	    	boolean directed = true;
	    	String scan;
			CopyOfGraph07042014 graph = new CopyOfGraph07042014();
			
			
			ArrayList<Integer> vertexFrom = new ArrayList<Integer>();
			ArrayList<Integer> vertexTo = new ArrayList<Integer>();
			ArrayList<Integer> weight = new ArrayList<Integer>();
			ArrayList<String> spanResults = new ArrayList<String>();        	
    	
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
            String s[] = null;

        	if(args[0].trim().equals("-u")){		//if the first argument was '-u'
        		while((scan = br.readLine()) != null)
        		{
//        		System.out.println(scan);	// in order to check if lines are read in a correct way
        			s = scan.split(" ");
        			graph.addVertex(s[0]);
        			graph.addVertex(s[1]);
        			graph.addEdge(s[0], s[1], Integer.valueOf(s[2]), directed);
//            		lineCounter++;
            	}
            }
        	else{        		
        		while((scan = br.readLine()) != null)
        		{
//        		System.out.println(scan);	// in order to check if lines are read in a correct way
        			s = scan.split(" ");
          			graph.addVertex(s[0]);
        			graph.addVertex(s[1]);
        			graph.addEdge(s[0], s[1], Integer.valueOf(s[2]), directed);
//
//              		vertexFrom.add(lineCounter, Integer.valueOf(s[0])); 
//            		weight.add(lineCounter, Integer.valueOf(s[1]));
//            		lineCounter++;
            	}
        	}
            br.close();

            
            argn = 0;
			if (args[argn].trim().equals("-u")){
				directed = false;
				argn++;
			}
			
			Set results;
			if (args[argn].trim().equals("-s")){
				argn++;
				Vertex sv = new Vertex(args[argn].trim());
				results = graph.dijkstraAlgorithm(sv);						
				argn++;
			}
			else if (args[argn].trim().equals("-a")){
				spanResults = graph.shortestPathAlgorithm(vertexFrom,vertexTo);			
				argn++;
			}
			else if (args[argn].trim().equals("-d")){
				spanResults = graph.graphDiameterAlgorithm(vertexFrom,vertexTo);			
				argn++;
			}
			
                        
            argn++;				// for the file reading
			

			if (args[argn].trim().equals(">")){
			    try {
		            argn++;
			        File outputFile = new File(args[argn]);
			        FileOutputStream is = new FileOutputStream(outputFile);
			        OutputStreamWriter osw = new OutputStreamWriter(is);    
			        Writer w = new BufferedWriter(osw);
			    	for (int i=0 ; i<spanResults.size() ; i++)
			    		w.write(spanResults.get(i)+"\n");
			        w.close();
			    } catch (IOException e) {
			        System.err.println("Problem writing to the file "+args[argn]);
			    }
		        System.out.println("Writing to the file "+args[argn]+" is DONE!");
			}
			else{
				for (int i=0 ; i<spanResults.size() ; i++)
					System.out.println(spanResults.get(i));
			}
		}
		else {			
			System.err.println("THIS PROGRAM WAS DEVELOPPED IN ECLIPSE. IT HAS 2-6 ARGUMENTS: [<TYPE_OF_DIRECTION>] <TYPE> [<STARTING NODE>] <CSV FILE> [<REDIRECTION_TO_FILE('>')>] [<OUTPUT FILE>]. EDIT IT FROM THE RUN CONFIGURATION");
			System.err.println("You haved typed a wrong number of arguments. You should type something like:\n '-u -s 0 traffic.txt' or \n '-u -s 0 traffic.txt > output.txt' in the Run Configuration of Eclipse. Try again...");
		}
	}
}

