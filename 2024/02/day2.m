lines = readlines("input.txt", "EmptyLineRule", "skip");

safe_count = 0;
damp_safe_count = 0;

function [safe] = is_safe(l)
    diff_arr = diff(l);
    safe = all(sign(diff_arr) == sign(diff_arr(1)));
    safe = safe & all(1 <= abs(diff_arr) & abs(diff_arr) <= 3);
end

for i = 1:length(lines)
    l = str2num(lines(i));
    safe = is_safe(l);
    safe_count = safe_count + safe;

    if ~safe
        for j = 1:length(l)
            l_t = l; l_t(j) = [];
            safe = is_safe(l_t);
            damp_safe_count = damp_safe_count + safe;
            if safe break, end
        end
    end
end

safe_count
damp_safe_count = damp_safe_count + safe_count
