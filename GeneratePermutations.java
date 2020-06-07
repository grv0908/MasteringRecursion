public class GeneratePermutations {
    public void permutations(char[] input, int start, int end) {
        // base conditions
        if (start >= end) {
            System.out.println(new String(input));
            return;
        }
        // Recursive calls
        for (int i = start; i < end; i++) {
            swap(input, i, start);
            permutations(input, start + 1, end);
            swap(input, i, start);
        }
    }
    public void swap(char[] input, int i, int j) {
        char c = input[i];
        input[i] = input[j];
        input[j] = c;
    }
    public static void main(String[] args) {
        GeneratePermutations g = new GeneratePermutations();
        char[] arr = new char[]{'A', 'B', 'C'};
        g.permutations(arr, 0, arr.length);
    }
}
