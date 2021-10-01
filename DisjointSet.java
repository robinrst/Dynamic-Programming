package Graph;

import java.util.HashMap;

public class DisjointSet<T> {

	private HashMap<T, Node> map = new HashMap<>();

	private class Node {
		T data;
		Node parent;
		int rank;

		public Node(T d, int r) {
			this.data = d;
			rank = r;
		}

		@Override
		public String toString() {
			return "Data: " + data + ", Parent:[" + parent.data + "] Rank: " + rank + ";";
		}
	}

	public void makeSet(T v) {

		Node rn = new Node(v, 0);
		rn.parent = rn;
		map.put(v, rn);
	}

	public void union(T data1, T data2) {

		Node node1 = map.get(data1);
		Node node2 = map.get(data2);

		Node parent1 = findSet(node1);
		Node parent2 = findSet(node2);

		if (parent1.rank >= parent2.rank) {
			parent1.rank = (parent1.rank == parent2.rank ? parent1.rank + 1 : parent1.rank);
			parent2.parent = parent1;
		} else {
			parent1.parent = parent2;
		}
	}

	public T findSet(T data) {
		return findSet(map.get(data)).data;
	}

	private Node findSet(Node node) {
		if (node.parent == node) {
			return node;
		}
		return node.parent = findSet(node.parent);
	}

	public void display() {
		for (T data : map.keySet())
			System.out.println(map.get(data));
	}
}
