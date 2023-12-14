private fun readStr() = readln() // string line
private fun readInt() = readStr().toInt() // single int
private fun readStrings() = readStr().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun solve(){
    val s=readLine()
    var cnt=0
    for(i in s.reversed()){
        if(i=='0') continue;
        cnt++
    }
    val ans:String
    var it=0
    for(i in s){
        it++;
        if(s.length-it!=cnt) ans=ans+i
    }
    println(ans)
}
fun main() {
    val t= readInt()
    repeat(t){
        solve()
    }
}