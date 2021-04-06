/*

 File:			A program that inserts 50 random integers from 1 to 100
 				in order into a Java LinkedList object. The program should sort 
 				the elements, then calculate the sum of the elements and the 
 				floating point average of the elements
 */
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Random;

public class FinalAssignment {

	public static void main(String[] args) {
		
		// create a random number generator to insert 
		Random rand = new Random(100);
		
		// create a linked list to store the random elements
		LinkedList<Integer> linkedList = new LinkedList<Integer>();
		// populate the list with a loop up to 50 elements
		for(int i = 0; i <50; i++) {
			linkedList.add(rand.nextInt(100));
		}
		
		// display what the list looks like unsorted
		System.out.println("This is the list before sorting: ");
		System.out.println(linkedList);
		
		// sort the list using bubblesort 
		Iterator<Integer> itr = linkedList.iterator();
		while(itr.hasNext()) {
			int[] array = new int[50];
			for(int i = 0; i < 50; i++) {
				array[i] = itr.next();
			}
			int n = array.length;
			for(int i = 0; i < n-1; i++) {
				if(array[i] < array[i+1]) {
					int tempValue = array[i];
					array[i] = array[i + 1];
					array[i+1] = tempValue;
				}
			}
		}
		// print out the sorted list
		Collections.sort(linkedList);
		System.out.println("\n" + "This is the list after sorting:");
		System.out.println(linkedList);
		// find the sum of elements of the linked list
		int sum = 0;
		for(Integer n: linkedList) {
			sum = sum + n;
		}
		
		// find the average of the elements in the linked list in floating point
		float average = 0;
		for(Integer n: linkedList) {
			average = sum / 50;
		}
		
		// print out statements
		System.out.println("\n" + "The sum of the elements are: " + sum);
		System.out.println("The average of the elements are: " + average);
		
	}

}
