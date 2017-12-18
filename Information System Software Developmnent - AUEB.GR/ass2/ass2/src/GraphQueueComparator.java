import java.util.Comparator;
import java.util.HashMap;

public class GraphQueueComparator implements Comparator<HashMap<String,Integer>>{

	    @Override
	    public int compare(HashMap<String,Integer> x, HashMap<String,Integer> y)
	    {
	        // Assume neither string is null. Real code should
	        // probably be more robust
	    	for (Integer i:x.values()){
	    		for (Integer j:y.values()){
	    			if (i < j)
	    			{
	    				return -1;
	    			}
	    		}
	    	}
	    	for (Integer i:x.values()){
	    		for (Integer j:y.values()){
	    			if (i > j)
	    			{
	    				return 1;
	    			}
	    		}
	    	}
	        return 0;
	    }
	
}
