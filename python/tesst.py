import numpy as np
import matplotlib.pyplot as plt

# 1. Khởi tạo dữ liệu (Initialize Data)
L = 1.0        # Chiều dài thanh
T = 0.1        # Tổng thời gian simulation
k = 1.0        # Hệ số truyền nhiệt
N = 10         # Số khoảng chia không gian
M = 50         # Số bước thời gian

dx = L / N
dt = T / M
alpha = k * dt / (dx**2)

# Kiểm tra điều kiện ổn định (Alpha nên <= 0.5)
print(f"Hệ số alpha: {alpha}")

# 2. Thiết lập lưới không gian và điều kiện ban đầu
x = np.linspace(0, L, N + 1)
u0 = np.sin(np.pi * x)  # u(x,0) = sin(pi*x)

# 3. Thuật toán sai phân (Numerical Scheme)
u1 = np.zeros(N + 1)

# Lưu lại kết quả tại một số mốc thời gian để simulate
history = [u0.copy()]

for j in range(1, M + 1):
    # Tính các điểm bên trong (từ chỉ số 1 đến N-1)
    for i in range(1, N):
        u1[i] = u0[i] + alpha * (u0[i+1] - 2*u0[i] + u0[i-1])
    
    # 4. Áp dụng điều kiện biên (Boundary Conditions)
    u1[0] = 0
    u1[N] = 0
    
    # Cập nhật để tính bước tiếp theo
    u0 = u1.copy()
    if j % 10 == 0: # Lưu lại mỗi 10 bước để vẽ đồ thị
        history.append(u0.copy())

plt.figure(figsize=(8, 6))
plt.imshow(u, extent=[0, L, T, 0], aspect='auto', cmap='hot')
plt.colorbar(label='Nhiệt độ (u)')
plt.title("Bảng 2D: Sự thay đổi nhiệt độ theo Không gian (X) và Thời gian (T)")
plt.xlabel("Vị trí (x)")
plt.ylabel("Thời gian (t)")
plt.show()