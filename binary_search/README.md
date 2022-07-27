# Binary Search

use mid = l + (r-l)/2 with l = mid + 1 and r = mid, and use mid = r - (r-l)/2 with l = mid and r = mid - 1. This can prevent mid from stucking at r (or l) after the updating step.
