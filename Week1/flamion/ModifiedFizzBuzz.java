import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();

        Map<Integer, String> replaceLookup = new HashMap<>();

        for (int i = 0; i < m; i++) {
            replaceLookup.put(scanner.nextInt(), scanner.next());
        }

        StringBuilder builder = new StringBuilder();

        for (int i = 1; i <= n; i++) {
            for (int j : replaceLookup.keySet()) {
                if (i % j == 0) {
                    builder.append(replaceLookup.get(j));
                }
            }
            System.out.println(builder.isEmpty() ? i : builder);
            builder.setLength(0);
        }
    }
}
