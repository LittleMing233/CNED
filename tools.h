/*
This code is intended for academic use only.
You are free to use and modify the code, at your own risk.

If you use this code, or find it useful, please refer to the paper:
Qi Jia, Xin Fan*, Zhongxuan Luo, Lianbo Song, and Tie Qiu, 
��A Fast Ellipse Detector Using Projective Invariant Pruning��, 
IEEE Transactions on Image Processing, 26(8): 3665-3679, 2017. 

http://ieeexplore.ieee.org/document/7929406/
Digital Object Identifier: 10.1109/TIP.2017.2704660

The comments in the code refer to the abovementioned paper.
If you need further details about the code or the algorithm, please contact me at:
lianbosong#foxmail.com

last update: 
*/

#pragma once

#define V2SP Point2f p3,Point2f p2,Point2f p1,Point2f p4,Point2f p5,Point2f p6
float value4SixPoints(V2SP);
Point2f lineCrossPoint(Point2f l1p1, Point2f l1p2, Point2f l2p1, Point2f l2p2 );
void point2Mat(Point2f p1, Point2f p2, float mat[2][2]);

//for Validate
void DrawDetectedEllipses(Mat3b& output, vector<Ellipse>& ellipses, 
						  int iTopN=0, int thickness=2);
void SaveEllipses(const string& fileName, const vector<Ellipse>& ellipses);
void LoadGT(vector<Ellipse>& gt, const string& sGtFileName, 
			bool bIsAngleInRadians = true);
bool LoadTest(vector<Ellipse>& ellipses, const string& sTestFileName, 
			  vector<double>& times, bool bIsAngleInRadians = true);
bool TestOverlap(const Mat1b& gt, const Mat1b& test, float th);
int Count(const vector<bool> v);
vector<float> Evaluate(const vector<Ellipse>& ellGT, 
					   const vector<Ellipse>& ellTest, 
					   const float th_score, const Mat3b& img);
// show Result
void showResult(vector<double> timesAndRecognize);
vector<float> getRecognizeResult(string sWorkingDir, string imagename,
								 vector<Ellipse> ellsCned,
								 float fThScoreScore, bool showpic=false);
