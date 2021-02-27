--[[
FIZS

Made for Problem of the Week 1: Modified FizzBuzz
]]

-- input: generic variable for taking in read()
-- max: amount of numbers to go through starting at 1
-- modifiers: amount of divisors you want
-- s: Generic (string) variable
local input, max, modifiers, s

-- Prints the FIZS logo in C O L O R
local function logo()
	local logo = {
		"FFFF I ZZZZ SSSS",
		"F    I    Z S   ",
		"FFFF I   Z  SSSS",
		"F    I  Z      S",
		"F    I ZZZZ SSSS"
	}
	for i = 1, 5 do
		term.blit(logo[i],"0000011222223333","ffffffffffffffff")
		print() -- \n doesn't work in blit so have fun lol
		os.sleep(0)
	end
end

-- Just making sure if you give me unnatural numbers or something, you stupid dummy, you moron, you fool
local function toNaturalNumber(x)
	return  math.floor(math.abs(tonumber(x)) or 1)
end

logo()
print()
-- Wait a few seconds, or just get to the point if the user is REALLY excited for (((fucking fizzbuzz)))
parallel.waitForAny(function() os.sleep(1) end, function() os.pullEvent("key") end)
-- step 1: get max and amount of modifiers
print("How many numbers and how many modifiers you want, separated by a space?")
os.sleep() -- hack so that if you press a key to quickly play, you dont put anything in read
-- Loop until valid input
repeat
	input = read()
	s = string.find(input, " ")
	-- This is valid input if there's a space and there's something before and after the space that are both numbers, and no extra crap
	if s and tonumber(string.sub(input, 1, s-1)) and tonumber(string.sub(input, s+1)) then
		-- Split input into max and modifiers between a space, also turning it into a number
		max = toNaturalNumber(string.sub(input, 1, s-1))
		modifiers = toNaturalNumber(string.sub(input, s+1))
	else
		print("Invalid. Please try again")
	end
until max and modifiers

-- step 2: get all of the modifiers

-- These two are paired together, and should ALWAYS be the same size.
-- N handles the divisor, W handles the word
local modifiersN, modifiersW = {}, {}
print("\nLet's set up your modifiers.\nThey'll replace the current modifier number with the word if it's divisible by the modifier number.\nWe'll do this step by step.\nThe structure is DIVISOR WORD")
for i = 1, modifiers do
	-- tracks if the input is good, if so move on to the next modifier
	local d = false
	repeat
		-- take input
		input = read(nil, nil, nil, (i+1).." ")
		s = string.find(input, " ")
		-- This is valid input if there's a space and there's something before the space that's a number, and after it is a word, and no extra crap
		if s and tonumber(string.sub(input, 1, s-1)) and string.sub(input, s+1) ~= "" then
			-- extract stuff into modifiersN, modifiersW
			table.insert(modifiersN, toNaturalNumber(string.sub(input, 1, s-1)))
			table.insert(modifiersW, string.sub(input, s+1))
			d = true
		else
			print("Invalid. Please try again")
		end
	until d
end
if #modifiersN ~= #modifiersW then
	error("Modifier table sizes don't match.\nThis should never happen!")
end
-- Step 3: Run modified fizzbuzz
local sx = {}
print()
term.setTextColor(colors.lightGray)
for i = 1, max do
	s = ""
	for k, v in ipairs(modifiersN) do
		if i % v == 0 then
			s = s..modifiersW[k]
		end
	end
	if s == "" then s = i end
	print(s)
	table.insert(sx, s)
	local event
	parallel.waitForAny(function() os.sleep() end, function() repeat local _, key = os.pullEvent("key") until key == keys.leftShift end)
end
term.setTextColor(colors.white)
print("\nAll done! Press CTRL to save to a file, anything else to exit")
os.sleep(1)
local _, key = os.pullEvent("key")
-- Save to file if desired
if key == keys.leftCtrl then
	print("Please enter the desired filepath:")
	input = read()
	-- Open up the path for writing
	s = fs.open(input, "w")
	for _, v in ipairs(sx) do s.write(v.."\n") end
	-- Submit writing and flush it into the file
	s.flush()
	s.close()
	print("Saved to "..input)
	os.sleep(1)
end