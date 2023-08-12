make 2>/dev/null | exit 1
output="$(./losersed MikuMikuNiiShiteAgeru Miku 'Hatsune Miku')"

count_addition=$(grep -c 'Addition' <<< "$output")
count_assignment=$(grep -c 'Assignment' <<< "$output")
count_construction=$(grep -c 'Constructor' <<< "$output")

echo "Constructor: $count_construction"
echo "Addition: $count_addition"
echo "Assignment: $count_assignment"