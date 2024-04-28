import java.io.*;
import java.util.*;

public class ExternalSorting {
    public static void main(String[] args) throws IOException {
        int m = 100; // Number of records that can be sorted in internal memory

        // Step 1: Split the input into sorted chunks
        splitInputIntoSortedChunks(m);

        // Step 2: Merge the sorted chunks using a k-way merge algorithm
        mergeSortedChunks(m);
    }

    private static void splitInputIntoSortedChunks(int m) throws IOException {
        // Open the input file
        BufferedReader inputFile = new BufferedReader(new FileReader("input.txt"));

        // Create temporary files for storing the sorted chunks
        List<File> sortedChunks = new ArrayList<>();

        // Read m records at a time, sort them, and write them to temporary files
        List<Integer> records = new ArrayList<>();
        String line;
        while ((line = inputFile.readLine()) != null) {
            int record = Integer.parseInt(line);
            records.add(record);

            if (records.size() == m) {
                Collections.sort(records);
                File sortedChunk = writeSortedChunk(records);
                sortedChunks.add(sortedChunk);
                records.clear();
            }
        }

        // Sort and write the remaining records to a temporary file
        if (!records.isEmpty()) {
            Collections.sort(records);
            File sortedChunk = writeSortedChunk(records);
            sortedChunks.add(sortedChunk);
        }

        // Close the input file
        inputFile.close();
    }

    private static File writeSortedChunk(List<Integer> records) throws IOException {
        File sortedChunk = File.createTempFile("sorted_chunk_", ".txt");
        BufferedWriter outputFile = new BufferedWriter(new FileWriter(sortedChunk));

        for (int record : records) {
            outputFile.write(Integer.toString(record));
            outputFile.newLine();
        }

        outputFile.close();
        return sortedChunk;
    }

    private static void mergeSortedChunks(int m) throws IOException {
        // Open the output file
        BufferedWriter outputFile = new BufferedWriter(new FileWriter("output.txt"));

        // Open the sorted chunks
        List<BufferedReader> sortedChunkReaders = new ArrayList<>();
        List<File> sortedChunks = new ArrayList<>(); // Declare and initialize sortedChunks
        for (File sortedChunk : sortedChunks) {
            BufferedReader sortedChunkReader = new BufferedReader(new FileReader(sortedChunk));
            sortedChunkReaders.add(sortedChunkReader);
        }

        // Perform a k-way merge using a priority queue
        PriorityQueue<Record> minHeap = new PriorityQueue<>();
        for (int i = 0; i < sortedChunkReaders.size(); i++) {
            BufferedReader sortedChunkReader = sortedChunkReaders.get(i);
            String line = sortedChunkReader.readLine();
            if (line != null) {
                int record = Integer.parseInt(line);
                minHeap.add(new Record(record, i));
            }
        }

        while (!minHeap.isEmpty()) {
            Record minRecord = minHeap.poll();
            outputFile.write(Integer.toString(minRecord.value));
            outputFile.newLine();

            BufferedReader sortedChunkReader = sortedChunkReaders.get(minRecord.chunkIndex);
            String line = sortedChunkReader.readLine();
            if (line != null) {
                int record = Integer.parseInt(line);
                minHeap.add(new Record(record, minRecord.chunkIndex));
            }
        }

        // Close the output file
        outputFile.close();

        // Close the sorted chunk readers
        for (BufferedReader sortedChunkReader : sortedChunkReaders) {
            sortedChunkReader.close();
        }
    }

    private static class Record implements Comparable<Record> {
        int value;
        int chunkIndex;

        public Record(int value, int chunkIndex) {
            this.value = value;
            this.chunkIndex = chunkIndex;
        }

        @Override
        public int compareTo(Record other) {
            return Integer.compare(this.value, other.value);
        }
    }
}