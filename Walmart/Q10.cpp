class Solution {
public:
    double xCenter;
    double yCenter;
    double radius;
    Solution(double rad, double x_center, double y_center) {
        radius = rad;
        xCenter = x_center;
        yCenter = y_center;
    }
    
    double random(){
        return 1.0 * rand() / RAND_MAX;
    }
   
    vector<double> randPoint() {
		// Imagine circle of rad = 1(c1) & rad = 2(c2): 
		// If length is randomly choosen, it has equal probability of beign anywhere [0,radius].
		// We want prob of point beign in circle: p(c2) = 4 * p(c1) - why?(compare area).
		// We take sqrt(length) -> if length = [0,1] the point belongs to c1 and if length = [0,4] the           point belongs to c2
        
        double length = sqrt(random()) * radius;
        double angle = random() * 2 * M_PI;
        double xRand = xCenter + length * cos(angle), yRand = yCenter + length * sin(angle);
        return {xRand, yRand};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */