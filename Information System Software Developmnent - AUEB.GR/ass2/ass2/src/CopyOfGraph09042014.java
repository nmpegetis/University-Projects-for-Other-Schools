import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.SortedSet;
import java.util.Stack;
import java.util.TreeSet;

public class CopyOfGraph09042014 {

	/**
	 * @param args
	 */

/*	public Integer extractMin(PriorityQueue<Integer> pq, ArrayList<Integer> dist){
		int queueSize = pq.size();
		int minDist = Integer.MAX_VALUE;
		int arrayIndex = 0;
		for(Integer i : pq.){
			if (pq.element().get(i) < minDist){
				minDist = pq.element().get(i);
				arrayIndex = i;
			}
		}
		return arrayIndex;
	}
*/	

	public Integer update(PriorityQueue<ArrayList<Integer>> pq, Integer v, Integer d){
		pq.element().get(i);
				arrayIndex = i;
			}
		}
		return arrayIndex;
	}

	
	public ArrayList<String> dijkstraAlgorithm (HashMap<String, HashMap<String,Integer>> g, String s) {
/**		Input: G = (V,E,s), a graph and a starting node s
		Output: (pred,dist): pred is an array of size |V| such that pred[i] is the
				predecessor of node i in the shortest path from s; dist is an array of
				size |V| such that dist[i] is the length of the shortest path calculated
				from node s to i
		Data: pq, a priority queue of nodes that prioritises by the path length to a
				node
*/		
		SortedSet<Integer> set = new TreeSet<Integer>();
//		ArrayList<String> dist = new ArrayList<String>(set);
		HashMap<String,Integer> dist = new HashMap<String,Integer>();
		HashMap<String,String> pred = new HashMap<String,String>();

		
//		Queue<String> pq = new PriorityQueue<String>(set);
//		Queue<Integer> pq = new LinkedList<Integer>();
//		Queue<Integer> pq = new PriorityQueue<Integer>();
//		Queue<Integer> pq = new PriorityQueue<Integer>();
		Comparator<HashMap<String, Integer>> comparator = new GraphQueueComparator();
//        PriorityQueue<String> pq = new PriorityQueue<String>(10, comparator);
		PriorityQueue<HashMap<String,Integer>> pq = new PriorityQueue<HashMap<String,Integer>>(10,comparator);
		
		String u;

		for (String v : g.keySet()){
			pred.put(v, "-1");
			if (!v.equals(s)){				
				dist.put(v, Integer.MAX_VALUE);
			}
			else{
				dist.put(v, 0);				
			}
		}
		pq.add(dist);					// equal to presantation's algorithm "Insert(pq,v,dist[v])", inserts v in the queue pq and the value of v is stored in the 'dist' arrayList
		
		while (pq.size() != 0){
			u = pq.peek();
			for(String v : pq.)
			u = pq.poll();				// retrieves and removes the first item from the queue, sorted by dist value
			for (Integer v : vertexFrom) {				//representation of adjacency list
				for (Integer vTo : vertexTo) {
				if (v is next to vTo)
			}
		}
		
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
			CopyOfGraph09042014 graph = new CopyOfGraph09042014();
			
			HashMap<String,HashMap<String,Integer>> g = new HashMap<String,HashMap<String,Integer>>();
			HashMap<String,Integer> temp = new HashMap<String,Integer>();
//			ArrayList<Integer> vertexFrom = new ArrayList<Integer>();
//			ArrayList<Integer> vertexTo = new ArrayList<Integer>();
//			ArrayList<Integer> weight = new ArrayList<Integer>();
    	
			if (args[argn].trim().equals("-u")){
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
//              		vertexFrom.add(lineCounter, Integer.valueOf(s[0])); 
//            		vertexTo.add(lineCounter, Integer.valueOf(s[1])); 
//            		weight.add(lineCounter, Integer.valueOf(s[2]));
//            		lineCounter++;
        			temp.put(s[1],Integer.valueOf(s[2]));
        			g.put(s[0], temp);
        			temp.put(s[0],Integer.valueOf(s[2]));
        			g.put(s[1], temp);
            	}
            }
        	else{        		
        		while((scan = br.readLine()) != null)
        		{
//        		System.out.println(scan);	// in order to check if lines are read in a correct way
        			s = scan.split(" ");
//              		vertexFrom.add(lineCounter, Integer.valueOf(s[0])); 
//            		weight.add(lineCounter, Integer.valueOf(s[1]));
//            		lineCounter++;
          			temp.put(s[1],Integer.valueOf(s[2]));
        			g.put(s[0], temp);
        		}
        	}
            br.close();

            
            argn = 0;
			if (args[argn].trim().equals("-u")){
				directed = false;
				argn++;
			}
			
			if (args[argn].trim().equals("-s")){
				argn++;
				if ((start = Integer.valueOf(args[argn].trim())) >= 0){
//					results = graph.dijkstraAlgorithm(vertexFrom,vertexTo,weight,start,directed);						
					results = graph.dijkstraAlgorithm(g,start);						
					argn++;
				}
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

