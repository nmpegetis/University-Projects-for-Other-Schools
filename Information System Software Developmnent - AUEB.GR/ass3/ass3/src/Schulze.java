import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import org.json.*;


public class Schulze {
	
	private static ArrayList<String> candidates = null;
	private static ArrayList<ArrayList<Integer>> ballots = null;

	
	/**
	 * @param filename
	 * @return
	 */	
	public void parseJSON (String filename) {
		// read the json file

		FileReader file = null;
		try {
			file = new FileReader(filename);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
        BufferedReader br = new BufferedReader(file);
        JSONTokener tokener = new JSONTokener(br);
        JSONObject jsonObject = new JSONObject(tokener); //root
						
        candidates = new ArrayList<String>();
        ArrayList<Integer> ballot;	
    	ballots = new ArrayList<ArrayList<Integer>>();


        // get an array from the JSON object
        JSONArray candidatesJSON = (JSONArray) jsonObject.get("candidates");
        // get an array from the JSON object
        JSONArray ballotsJSON = (JSONArray) jsonObject.get("ballots");        
		

        // take the elements of the json array
		for(int i=0 ; i<candidatesJSON.length() ; i++){
			candidates.add((String) candidatesJSON.get(i));
			// System.out.println("The " + i + " element of the array candidatesJSON: "+candidates.get(i));
		}
		
        for (int i=0 ; i<ballotsJSON.length() ; i++){
        	//ballots.add(ballotsJSON.getJSONArray(i));
        	ballot = new ArrayList<Integer>();
            for(int j=0 ; j<ballotsJSON.getJSONArray(i).length() ; j++){
            	ballot.add(j, ballotsJSON.getJSONArray(i).getInt(j));
            }
            ballots.add(ballot);
		}
	}
	

	/**
	 * @param 
	 * @return
	 */	
	public void printParseJSON(){
    	System.out.println("Candidates:");
        for (String s : candidates){
        	System.out.print(s+", ");
        }
    	System.out.println("");

    	System.out.println("Ballots:");
        for (ArrayList<Integer> a : ballots){
        	System.out.print("[");
            for (Integer i : a){
            	System.out.print(i+", ");
            }
        	System.out.println("]");
        }
    	System.out.println("");
	}
	
	

	/**
	 * @param
	 * @return p
	 */	
	private int[][] calcPairwisePreferences() {
	/**	Input: ballots, n, m: ballots is an array of ballots, of size n. Each ballot is an
			array of candidates. m is the number of candidates.
		Output: p: an array of size m X m with the pairwise preferences for
			candidates; p[i, j] is the number of voters that prefer candidate i to
			candidate j.
	 */
		int n = ballots.size();
		int m = candidates.size();
		int[][] p = new int[m][m];
		
		ArrayList<Integer> b = null;
		int f,s;
		
		for (int i=0 ; i<m ; i++){
			for (int j=0 ; j<m ; j++){
				p[i][j] = 0;
			}
		}
		
		for (int i=0 ; i<n ; i++){
			b = new ArrayList<Integer>();
			b = ballots.get(i);
			for (int j=0 ; j<b.size() ; j++){
				f = b.get(j);
				for (int k=j+1 ; k<b.size() ; k++){
					s = b.get(k);
					p[f][s] += 1;
				}
			}
		}
		
		return p;
	}

	
	/**
	 * @param strongestPaths
	 * @return
	 */	
	public void printCalcStrongestPaths(ArrayList<int[][]> strongestPaths ){
		for (int i=0 ; i<strongestPaths.size() ; i++){
			if (i == 0)
				System.out.println("Strongest Path:");
			else
				System.out.println("Predecessor List:");

			for (int j=0 ; j<candidates.size() ; j++){
				for (int k=0 ; k<candidates.size() ; k++){
					System.out.println(strongestPaths.get(i)[j][k]);
				}				
			}
		}
	}

	
	/**
	 * @param w
	 * @param n
	 * @return strongestPaths
	 */	
	public ArrayList<int[][]> calcStrongestPaths(int w[][], int n){
	/** Input: w, n: w is an array of size n X n representing the adjacency matrix of
			a graph; w[i, j] is the weight of the edge between nodes i and j.
		Output: (s, pred): s is an array of size n X n such that s[i, j] is the strongest
			path between nodes i and j. pred is an array of size n X n such that
			pred[i, j] is the predecessor of node i in the strongest path to node j.
	*/
		int[][] s = new int[n][n];
		int[][] pred = new int[n][n];
		ArrayList<int[][]> strongestPaths = new ArrayList<int[][]>();
		
		
		for (int i=0 ; i<n ; i++){
			for (int j=0 ; j<n ; j++){
				if (w[i][j] > w[j][i]){
					s[i][j] = w[i][j] - w[j][i];
					pred[i][j] = i;
				}
				else{
					s[i][j] = (int) Double.NEGATIVE_INFINITY;
					pred[i][j] = -1;
				}
			}
		}
		
		for (int k=0 ; k<n ; k++){
			for (int i=0 ; i<n ; i++){
				if (i != k){
					for (int j=0 ; j<n ; j++){
						if (j != i){
							if ( s[i][j] < Math.min(s[i][k], s[k][j])){
								s[i][j] = Math.min(s[i][k], s[k][j]);
								pred[i][j] = pred[k][j];
							}
						}
					}
				}
			}
		}
		
		strongestPaths.add(s);
		strongestPaths.add(pred);
		
		return strongestPaths;
	}
	
	
	/**
	 * @param p
	 * @return
	 */	
	public void printCalcPairwisePreferences(int[][] p){
		for (int i=0 ; i<candidates.size() ; i++){
			for (int j=0 ; j<candidates.size() ; j++){
				System.out.println("p["+i+"]["+j+"] = "+p[i][j]);
			}				
		}
	}

	
	/**
	 * @param s
	 * @param n
	 * @return wins
	 */	
	public ArrayList<ArrayList<Integer>> calculateResults(int[][] s, int n) {
	/**	Input: s, n: an array of size n X n with the strongest paths between nodes;
			s[i, j] is the strongest path between nodes i and j.
		Output: wins: a list of size n. Item i of wins is a list containing m integer
			items j1, j2, ..., jm for which s[i, jk] > s[jk, i].
	 */	
		
		ArrayList<ArrayList<Integer>> wins = new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> listRows = null;
		
		for (int i=0 ; i<n ; i++){
			listRows = new ArrayList<Integer>();
			wins.add(listRows);
			for (int j=0 ; j<n ; j++){
				if (i!=j){
					if(s[i][j] > s[j][i]){
						listRows.add(j);
					}
				}
			}
		}

		return wins;
	}
	
	
	/**
	 * @param wins
	 */	
	public void printCalculateResults(ArrayList<ArrayList<Integer>> wins) {
		System.out.print("WINS = [");
		for (int i=0 ; i<wins.size() ; i++){
			System.out.print("[");
			for (int j=0 ; j<wins.get(i).size() ; j++){
				if(j!=(wins.get(i).size()-1))
					System.out.print(candidates.get(wins.get(i).get(j))+", ");		//candidates printing
				else
					System.out.print(candidates.get(wins.get(i).get(j)));		//candidates printing
			}			
			System.out.print("]");
		}
		System.out.println("]");
		
		
		System.out.println("\nor \n\nWINS:");
		for (int i=0 ; i<wins.size() ; i++){
			System.out.print(candidates.get(i)+" = "+wins.get(i).size()+" [");
			for (int j=0 ; j<wins.get(i).size() ; j++){
				if(j!=(wins.get(i).size()-1))
					System.out.print(candidates.get(wins.get(i).get(j))+", ");		//candidates printing
				else
					System.out.print(candidates.get(wins.get(i).get(j)));		//candidates printing
			}			
			System.out.println("]");
		}
		
	}


	
	public static void main(String[] args) throws IOException {
    
		if (args.length == 1){
			Schulze schulze = new Schulze();
			schulze.parseJSON(args[0]);
			//schulze.printParseJSON();			
			
			int p[][] = new int[candidates.size()][candidates.size()];
	        
			p = schulze.calcPairwisePreferences();
			//schulze.printCalcPairwisePreferences(p);
			
			ArrayList<int[][]> strongestPaths = new ArrayList<int[][]>();

			strongestPaths = schulze.calcStrongestPaths(p, candidates.size());
			//schulze.printCalcStrongestPaths(strongestPaths);
			
			ArrayList<ArrayList<Integer>> wins = new ArrayList<ArrayList<Integer>>();
			
			wins = schulze.calculateResults(strongestPaths.get(0), candidates.size());	// get(0) refers to the s array
			schulze.printCalculateResults(wins);

		}
		else {			
			System.err.println("THIS PROGRAM WAS DEVELOPPED IN ECLIPSE. IT HAS 1-3 ARGUMENTS: <JSON FILE> [<REDIRECTION_TO_FILE('>')>] [<OUTPUT FILE>]. EDIT IT FROM THE RUN CONFIGURATION");
			System.err.println("You haved typed a wrong number of arguments. You should type something like:\n 'example_elections.json' or \n 'example_elections.json > output.txt' in the Run Configuration of Eclipse. Try again...");
		}
	}	
}

