# Prey-Predator Evolution Simulation

## 📌 Overview
This project is a **2D prey-predator simulation** where two species interact in an open environment. The prey searches for food while avoiding predators, and predators hunt prey. The system includes **random mutations** that allow species to evolve over time.

## 🎯 Features
- **Prey and Predator AI**: Movement based on collision detection and sight.
- **Food Generation**: Random food spawns for prey to consume.
- **Genetic Algorithm**:
  - Prey and predators inherit traits from parents.
  - Random mutations in speed, vision, and other stats.
  - Natural selection: The best-adapted individuals survive and reproduce.
- **Grid-Based World**: Efficient food detection and movement logic.

## 🏗️ How It Works
### **Genetic Algorithm Process**
- **Mutation:** Small changes to speed & vision per generation.
- **Inheritance:** Offspring inherit stats from surviving parents.
- **Selection:** The best-adapted individuals pass on their traits.

### **Behavior**
- **Prey searches for food** and reproduces upon eating enough.
- **Predators chase prey** and reproduce if they eat enough.
- **If prey population decreases, predators struggle** → Balancing effect.

## 📜 License
This project is under the **MIT License**.

## 🤝 Contributing
Pull requests are welcome! If you have ideas to improve the simulation, feel free to fork and contribute.


