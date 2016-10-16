int switch_prob(int x, int n) {
	int result = x;

	switch(n) {
	case 40:
	case 42:
		result <<= 3;
		break;
	case 43:
		result >>= 3;
		break;
	case 44:
		result *= 7;
	case 45:
		result *= result;
	default:
		result += 17;
	}
	return result;
}
