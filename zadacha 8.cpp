int days(std::vector<int> flowers) {
    if (flowers.empty() || flowers.size() == 1)
        return 0;

    for (unsigned int i = 0; i < flowers.size()-1; i++) {
        if (flowers[i] < flowers[i+1]){
            std::stack<int> s;

            s.push(flowers[0]);

            for (unsigned int i = 1; i < flowers.size(); i++) {
                if (s.top() >= flowers[i])
                    s.push(flowers[i]);
            }

            std::vector<int> result;
            while (!s.empty()) {
                result.push_back(s.top());
                s.pop();
            }

            return days(result) + 1;
        }
    }

    return 0;
}
