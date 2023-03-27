 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;


// Function to calculate the Euclidean distance between two points
double distance(vector<double>& point1, vector<double>& point2) {
    double sum = 0.0;
    for (int i = 0; i < point1.size(); ++i) {
        sum += pow(point1[i] - point2[i], 2);
    }
    return sqrt(sum);
}

// Function to assign each point to its nearest centroid
void assign_clusters(vector<vector<double>>& points, vector<vector<double>>& centroids, vector<int>& clusters) {
    for (int i = 0; i < points.size(); ++i) {
        double min_distance = distance(points[i], centroids[0]);
        int cluster = 0;
        for (int j = 1; j < centroids.size(); ++j) {
            double d = distance(points[i], centroids[j]);
            if (d < min_distance) {
                min_distance = d;
                cluster = j;
            }
        }
        clusters[i] = cluster;
    }
}

// Function to update the centroid of each cluster
void update_centroids(vector<vector<double>>& points, vector<vector<double>>& centroids, vector<int>& clusters) {
    for (int i = 0; i < centroids.size(); ++i) {
        vector<double> new_centroid(centroids[i].size(), 0.0);
        int count = 0;
        for (int j = 0; j < points.size(); ++j) {
            if (clusters[j] == i) {
                for (int k = 0; k < points[j].size(); ++k) {
                    new_centroid[k] += points[j][k];
                }
                ++count;
            }
        }
        if (count > 0) {
            for (int k = 0; k < new_centroid.size(); ++k) {
                new_centroid[k] /= count;
            }
            centroids[i] = new_centroid;
        }
    }
}

// Function to initialize the centroids randomly
void initialize_centroids(vector<vector<double>>& points, vector<vector<double>>& centroids, int k) {
    srand(time(NULL));
    int n = points.size();
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }
    random_shuffle(indices.begin(), indices.end());
    for (int i = 0; i < k; ++i) {
        centroids.push_back(points[indices[i]]);
    }
}

// Function to run the k-means algorithm
void k_means(vector<vector<double>>& points, int k, vector<vector<double>>& centroids, vector<int>& clusters, int max_iterations) {
    initialize_centroids(points, centroids, k);
    int n = points.size();
    clusters.resize(n, -1);
    for (int iter = 0; iter < max_iterations; ++iter) {
        assign_clusters(points, centroids, clusters);
        update_centroids(points, centroids, clusters);
    }
}

int main() {
    // Load the CSV file
    ifstream file("data.csv");
    string line;
    vector<vector<double>> points;

    // skip the first line of the file
    std::getline(file, line);
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        vector<double> point;
        while (getline(ss, value, ',')) {
            point.push_back(stod(value));
        }
        points.push_back(point);
    }

    // Apply k-means algorithm
    int k = 2; // number of clusters
    int max_iterations = 100; // maximum number of iterations
    vector<vector<double>> centroids; // centroids of the clusters
    vector<int> clusters; // cluster assignment for each point
    k_means(points, k, centroids, clusters, max_iterations);

    // Write the results to a CSV file
    ofstream output_file("results.csv");
    output_file << "Feature1,Feature2,Feature3,Feature4,Feature5,Feature6,Feature7,Feature8,Feature9,Feature10,Feature11,Feature12,Feature13,Cluster\n";
    for (int i = 0; i < points.size(); ++i) {
        for (int j = 0; j < points[i].size(); ++j) {
            output_file << points[i][j] << ",";
        }
        output_file << clusters[i] << "\n";
    }
    output_file.close();

    return 0;
}