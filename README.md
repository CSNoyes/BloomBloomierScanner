# BloomBloomierScanner
Implementation of the data structure described in the BitAV paper. Essentially, this allows a user to do O(1) membership AND lookup queries.
A bloom filter is first queueried for membership; if that query returns true, a bloomier filter is checked for the same hash, and the result is returned.
