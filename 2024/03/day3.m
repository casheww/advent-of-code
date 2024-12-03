lines = readlines("input.txt");

pairs = regexp(lines, "(do(n't)?)\(\)|mul\(([0-9]{1,3}),([0-9]{1,3})\)", "tokens");

function [product] = mul(args)
    v = arrayfun(@str2num, args);
    product = v(1) * v(2);
end

tot = 0;
do_mul = true;

for i = 1:length(pairs)
for j = 1:length(pairs{i})
    group1 = pairs{i}{j}(1);
    if group1 == "do"
        do_mul = true;
    elseif group1 == "don't"
        do_mul = false;
    end

    if do_mul & all(["do" "don't"] ~= group1)
        tot = tot + mul(pairs{i}{j});
    end
end
end

tot
