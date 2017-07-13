
static int viterbi_decode(const Eigen::TensorMap<Eigen::Tensor<float, 3, Eigen::RowMajor>, Eigen::Aligned>& predictions,int sentenceIdx,
  int nn, const std::vector<std::vector<float>>& trans, std::vector<std::vector<int>>& bp,int ntags) 
{
  std::vector<std::vector<float>> scores(2);
  for (int i = 0; i < ntags; i++) {
    scores[0].push_back(predictions(sentenceIdx, 0, i));
  }
  scores[1].resize(ntags);
  for (int i = 1; i < nn; i++) {
    for (int  t = 0; t < ntags; t++) {
      float maxScore = -1e7;
      float emission = predictions(sentenceIdx, i, t);
      for (int prev = 0; prev < ntags; prev++) {
        float score = scores[(i - 1) % 2][prev] + trans[prev][t] + emission;
        if (score > maxScore) {
          maxScore = score;
          bp[i - 1][t] = prev;
        }
      }
      scores[i % 2][t] = maxScore;
    }
  }
  float maxScore = scores[(nn - 1) % 2][0];
  int ret = 0;
  for (int i = 1; i < ntags; i++) {
    if (scores[(nn - 1) % 2][i] > maxScore) {
      ret = i;
      maxScore = scores[(nn - 1) % 2][i];
    }
  }
  return ret;
}


static void get_best_path(
  const Eigen::TensorMap<Eigen::Tensor<float, 3, Eigen::RowMajor>, Eigen::Aligned>& predictions,
  int sentenceIdx,
  int nn,
  const std::vector<std::vector<float>>& trans,
  std::vector<int>& resultTags,
  int ntags) {
  std::vector<std::vector<int>> bp(nn - 1);
  for (int i = 1; i < nn; i++) {
    for (int t = 0; t < ntags; t++) {
      bp[i - 1].push_back(-1);
    }
  }
  int lastTag = viterbi_decode(predictions, sentenceIdx, nn, trans, bp, ntags);
  resultTags.push_back(lastTag);
  for (int i = nn - 2; i >= 0; i--) {
    int bpTag = bp[i][lastTag];
    resultTags.push_back(bpTag);
    lastTag = bpTag;
  }
}

















