import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)

    val n = scanner.nextInt()
    val m = scanner.nextInt()

    val replaceLookup: MutableMap<Int, String> = java.util.HashMap()

    for (i in 0 until m) {
        replaceLookup[scanner.nextInt()] = scanner.next()
    }

    val builder = StringBuilder()

    for (i in 1..n) {
        for (j in replaceLookup.keys) {
            if (i % j == 0) {
                builder.append(replaceLookup[j])
            }
        }
        println(if (builder.isEmpty()) i else builder)
        builder.setLength(0)
    }
}
