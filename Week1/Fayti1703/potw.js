function(c,a) {
	let input = a.i.split("\n"),
	limit = input.shift().split(" ")[0],
	map = Object.fromEntries(input.map(e => e.split(" "))),
	output = []

	for(let subj = 1; subj <= limit; subj++) {
		let out = "";
		for(let factor in map) {
			if(subj % factor-0 == 0)
				out += map[factor]
		}
		if(output == "") out = t + ""
		output.push(out)
	}
	return output
}
