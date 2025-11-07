<p align="center" style="margin:0;">
  <img 
    src="https://res.cloudinary.com/dwjbed2xb/image/upload/v1762524349/vixai_snfafp.png" 
    alt="Vix.AI Banner" 
    width="100%" 
    style="
      display:block;
      height:auto;
      max-width:900px;
      margin:auto;
      object-fit:cover;
      border-radius:8px;
    ">
</p>

<h1 align="center">Vix.AI</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C++20-Standard-blue">
  <img src="https://img.shields.io/badge/License-MIT-green">
</p>

# 🧠 **Vix.AI** — Modular AI Framework in Modern C++

> **“AI at native speed.”**  
> Vix.AI brings the performance and clarity of C++ to modern machine learning, deep learning, NLP, vision, and distributed intelligence.

---

## 🚀 Vision

**Vix.AI** is a **modular artificial intelligence framework** written in **modern C++20**, designed for **speed, modularity, and extensibility**.  
It’s part of the **Vix.cpp ecosystem**, a new generation of backend and AI tools designed for developers who want **Python-like productivity** with **C++-level performance**.

Our vision is to make **high-performance AI natively available** in C++ — from linear regression to distributed neural computation — all within a **cohesive, elegant architecture**.

---

## 🧩 Modular Architecture

Each core domain of AI is developed as an independent C++ module:

| Module                    | Description                                                                 |
| :------------------------ | :-------------------------------------------------------------------------- |
| 🧮 **vix-ai-ml**          | Classical Machine Learning — regression, clustering, preprocessing, metrics |
| 🧠 **vix-ai-nn**          | Neural Networks — layers, optimizers, forward/backpropagation               |
| 🗣️ **vix-ai-nlp**         | Natural Language Processing — tokenization, embeddings, text models         |
| 👁️ **vix-ai-vision**      | Computer Vision — image preprocessing, feature extraction, object detection |
| 🌐 **vix-ai-distributed** | Distributed AI — peer-to-peer model training, parallel inference            |
| 💡 **vix-ai-core**        | Core abstractions — engine, device, tensor primitives, memory               |
| ⚙️ **vix-ai-cli**         | Command-line utilities, experiments runner, and dataset manager             |

All modules are **independent repositories** managed via **Git submodules** — allowing parallel development, easy reuse, and lightweight integration in other projects.

---

## 🧱 Build & Test

### 🔧 Prerequisites

- **CMake ≥ 3.20**
- **C++20 compiler** (GCC ≥ 12 / Clang ≥ 14 / MSVC ≥ 19.3)
- Optional: `make`, `ctest`, `ninja`

### ⚙️ Build from source

```bash
git clone --recurse-submodules https://github.com/vixcpp/vix-ai.git
cd vix-ai
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

### ✅ Run tests

```bash
cd build
ctest --output-on-failure
```

---

## 📚 Examples

Vix.AI includes a growing set of examples under `/examples`:

| Example                                | Description                         |
| :------------------------------------- | :---------------------------------- |
| `examples/01_minimal.cpp`              | Minimal example with Vix.AI Core    |
| `examples/02_ml_minimal.cpp`           | Linear Regression demo              |
| `examples/ml/02_regression_kmeans.cpp` | Regression + KMeans clustering demo |

Run any example manually after build:

```bash
./build/examples/vix_ai_example_ml_regression_kmeans
```

---

## 🧬 Example: Linear Regression + KMeans

```cpp
#include <vix/ai/ml/Regression.hpp>
#include <vix/ai/ml/Clustering.hpp>
#include <vix/ai/ml/Metrics.hpp>
#include <iostream>
#include <random>

using namespace vix::ai::ml;

int main() {
    // Regression: y ≈ 2x + 1 + noise
    std::mt19937 rng(7);
    std::normal_distribution<double> noise(0.0, 0.2);
    Mat X; Vec y;
    for (int i = 0; i < 200; ++i) {
        double x = i * 0.05;
        X.push_back({x});
        y.push_back(2.0 * x + 1.0 + noise(rng));
    }

    LinearRegression lr;
    lr.set_hyperparams(0.1, 3000);
    lr.fit(X, y);
    std::cout << "[MSE] " << mse(y, lr.predict(X)) << "\n";

    // KMeans clustering
    KMeans km(2, 50);
    km.fit(X);
    std::cout << "[KMeans] k = " << km.k() << "\n";
}
```

---

## 🧭 Roadmap

| Phase      | Focus                                             |
| :--------- | :------------------------------------------------ |
| ✅ Phase 1 | Core ML algorithms (Regression, KMeans, PCA, SVM) |
| 🚧 Phase 2 | Deep Learning (NN layers, optimizers, autodiff)   |
| 🔜 Phase 3 | NLP & Vision integration                          |
| 🌍 Phase 4 | Distributed training & deployment                 |
| 💫 Phase 5 | Unified AI runtime via **VixEngine**              |

---

## 🧑‍💻 Contributing

Vix.AI welcomes contributions — from small bug fixes to new ML models.  
Each submodule (`vix-ai-ml`, `vix-ai-nn`, etc.) has its own issue tracker and test suite.

Clone the repo with submodules:

```bash
git clone --recurse-submodules https://github.com/vixcpp/vix-ai.git
```

---

## 🧩 Part of the Vix.cpp Ecosystem

| Project                                          | Description                               |
| :----------------------------------------------- | :---------------------------------------- |
| [**Vix.cpp**](https://github.com/vixcpp/vix)     | High-performance backend framework in C++ |
| [**Vix.AI**](https://github.com/vixcpp/vix-ai)   | Modular AI framework (this repo)          |
| [**Vix.ORM**](https://github.com/vixcpp/vix-orm) | Modern C++ ORM                            |
| [**Vix.CLI**](https://github.com/vixcpp/vix-cli) | CLI tools for AI and backend workflows    |

---

## ⚖️ License

MIT License © 2025 [Vix.cpp Authors](https://github.com/vixcpp)  
Use freely, modify openly, contribute boldly. 🚀
