local function concat2(a, b)
	local result = {table.unpack(a)}
	table.move(b, 1, #b, #result + 1, result)
	return result
end

function concat(...)
	local result = {}
	for _, v in ipairs({...}) do
		if v == nil then 
			::continue::
		end
		result = concat2(result, v)
	end
	return result
end

modules_folder = "modules/"
