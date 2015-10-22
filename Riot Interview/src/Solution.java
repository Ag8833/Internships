import java.io.*;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution 
{

	static class Node
	{
	    public int beginningTime;
	    public int duration;
	    public int severity;

	    public Node(int b, int d, int s)
	    {
	    	beginningTime = b;
	    	duration = d;
	    	severity = s;
	    }
	};
	
	static class NodeResults
	{
	    public int timeChange;
	    public int severityChange;

	    public NodeResults(int t, int s)
	    {
	    	timeChange = t;
	    	severityChange = s;
	    }
	};
	
	static class TimeComparator implements Comparator<Node>
	{

		@Override
		public int compare(Node node1, Node node2) 
		{
			if(node1.beginningTime < node2.beginningTime)
			{
				return -1;
			}
			
			if(node1.beginningTime > node2.beginningTime)
			{
				return 1;
			}
			
			return 0;
		}	
	}
	
	public static void main(String[] args) 
	{
		Scanner myScanner = new Scanner(System.in);
		Comparator<Node> myComparator = new TimeComparator();
		int crowdControlEntries = myScanner.nextInt();
		PriorityQueue<Node> myHeap = new PriorityQueue<Node>(crowdControlEntries, myComparator);
        boolean finishedFlag = false;
		
		LinkedList<Node> myInputList = new LinkedList<Node>();
		LinkedList<NodeResults> myOutputList = new LinkedList<NodeResults>();
	
		int time = 0, outputEntries = 0;
		
		for(int i = 0; i < crowdControlEntries; i++)
		{
			int b = myScanner.nextInt();
			int d = myScanner.nextInt();
			int s = myScanner.nextInt();
			
			Node myNode = new Node(b, d, s);
			
			myHeap.offer(myNode);
		}
		
		time = myHeap.peek().beginningTime;
		
		while(finishedFlag == false)
		{
            while(myHeap.peek() != null)
            {
                if((myHeap.peek()).beginningTime == time)
			    {
				    myInputList.add(myHeap.remove());
			    }
                
                else
                {
                	break;
                }
            }
            
			if(myInputList.isEmpty() == false)
			{
				if(myOutputList.isEmpty() == true)
				{
					NodeResults largestNode = new NodeResults(time, myInputList.peek().severity);
					
					for(int j = 1; j < myInputList.size(); j++)
					{
						if(myInputList.get(j).severity > largestNode.severityChange)
						{
							largestNode.severityChange =  myInputList.get(j).severity;
						}
					}
					
					myOutputList.add(largestNode);
					outputEntries++;
				}
				
				else
				{
					NodeResults checkNode = new NodeResults(myOutputList.getLast().timeChange, myOutputList.getLast().severityChange);
					NodeResults largestNode = new NodeResults(time, myInputList.peek().severity);
					
					for(int j = 1; j < myInputList.size(); j++)
					{
						if(myInputList.get(j).severity > checkNode.severityChange && myInputList.get(j).severity > largestNode.severityChange)
						{
							largestNode.severityChange =  myInputList.get(j).severity;
						}
					}
					
					if(largestNode.severityChange != checkNode.severityChange)
					{
						myOutputList.add(largestNode);
						outputEntries++;
					}
				}
			}
			
			else if(myInputList.isEmpty() == true && myOutputList.isEmpty() == false)
			{
				NodeResults zeroSeverity = new NodeResults(time, 0);
				myOutputList.add(zeroSeverity);
				outputEntries++;
			}
			
			
			for(int k = 0; k < myInputList.size(); k++)
			{
				if((myInputList.get(k).duration + myInputList.get(k).beginningTime) == time + 1)
				{
					myInputList.remove(myInputList.get(k));
				}
			}
            
            if(myHeap.peek() == null && myInputList.peek() == null )
            {
                finishedFlag = true;
            }
            
            if(myHeap.peek() != null )
            {
            	if(myHeap.peek().beginningTime >= 100)
            	{
            		time = myHeap.peek().beginningTime;
            	}
            	time++;
            }
            else
            {
                time++;
            }
		}
		
		NodeResults zeroSeverity = new NodeResults(time--, 0);
		myOutputList.add(zeroSeverity);
		outputEntries++;
		
		System.out.println(outputEntries);
		while(myOutputList.peek() != null)
		{
			NodeResults outputNode = myOutputList.removeFirst();
			System.out.println(outputNode.timeChange + " " + outputNode.severityChange);
		}
		
		
	}
}
