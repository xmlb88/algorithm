ArrayList<LinkedList<Integer>> allSequences(TreeNode node) {
2 ArrayList<LinkedList<Integer>> result = new ArrayList<LinkedList<Integer>>();
34
if (node == null) {
5 result.add(new LinkedList<Integer>());
6 return result;
7 }
89
LinkedList<Integer> prefix = new LinkedList<Integer>();
10 prefix.add(node.data);
11
12 /* 对左右子树递归 */
13 ArrayList<LinkedList<Integer>> leftSeq = allSequences(node.left);
14 ArrayList<LinkedList<Integer>> rightSeq = allSequences(node.right);
15
16 /* 从每个链表的左右两端交替计算 */
17 for (LinkedList<Integer> left : leftSeq) {
18 for (LinkedList<Integer> right : rightSeq) {
19 ArrayList<LinkedList<Integer>> weaved =
20 new ArrayList<LinkedList<Integer>>();
21 weaveLists(left, right, weaved, prefix);
22 result.addAll(weaved);
23 }
24 }
25 return result;
26 }
27
28 /* 以所有可能的方式对链表同时交替计算。该算法从一个链表的头部移除元素，递归，
29 * 并对另一个链表做相同的操作 */
30 void weaveLists(LinkedList<Integer> first, LinkedList<Integer> second,
31 ArrayList<LinkedList<Integer>> results, LinkedList<Integer> prefix) {
32 /* 一个链表已空。将剩余部分加入到（复制后的） prefix 中并存储结果 */
33 if (first.size() == 0 || second.size() == 0) {
34 LinkedList<Integer> result = (LinkedList<Integer>) prefix.clone();
35 result.addAll(first);
36 result.addAll(second);
37 results.add(result);
38 return;
39 }
40
41 /* 将 first 的头部加入到 prefix 后进行递归。移除头部元素会破坏 first，
42 * 因此我们需要在后续操作时将元素放回 */
43 int headFirst = first.removeFirst();
44 prefix.addLast(headFirst);
45 weaveLists(first, second, results, prefix);
46 prefix.removeLast();
47 first.addFirst(headFirst);
48
49 /* 对 second 做相同操作，破坏链表并恢复 */
50 int headSecond = second.removeFirst();
51 prefix.addLast(headSecond);
52 weaveLists(first, second, results, prefix);
53 prefix.removeLast();
54 second.addFirst(headSecond);
55 }