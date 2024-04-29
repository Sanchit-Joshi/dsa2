class ShellSort {
    public void sort(int arr[]) {
        int n = arr.length;

        // Start with a big gap, then reduce the gap
        for (int gap = n / 2; gap > 0; gap /= 2) {
            // Do a gapped insertion sort for this gap size.
            for (int i = gap; i < n; i++) {
                // add a[i] to the elements that have been gap sorted
                int temp = arr[i];

                // shift earlier gap-sorted elements up until the correct location for a[i] is found
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];

                // put temp (the original a[i]) in its correct location
                arr[j] = temp;
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int arr[] = {12, 34, 54, 2, 3};
        ShellSort ss = new ShellSort();
        ss.sort(arr);

        System.out.println("Sorted array is");
        for (int i = 0; i < arr.length; ++i)
            System.out.print(arr[i] + " ");
    }
}
