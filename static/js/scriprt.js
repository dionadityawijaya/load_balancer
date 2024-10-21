document.addEventListener('DOMContentLoaded', () => {
    const servers = [
        { name: 'Server 1', connections: 0 },
        { name: 'Server 2', connections: 0 },
        { name: 'Server 3', connections: 0 }
    ];

    const updateServerUI = () => {
        const serverContainer = document.getElementById('servers');
        serverContainer.innerHTML = '';
        servers.forEach(server => {
            const serverEl = document.createElement('div');
            serverEl.classList.add('bg-white', 'p-4', 'rounded', 'shadow');
            serverEl.innerHTML = `
                <h2 class="text-xl font-bold">${server.name}</h2>
                <p>Connections: ${server.connections}</p>
            `;
            serverContainer.appendChild(serverEl);
        });
    };

    const handleRequest = () => {
        fetch('/api/request')  // Mengirim request ke backend
            .then(response => response.text())
            .then(data => {
                console.log(data);  // Bisa menampilkan respons di console
                updateServerUI();  // Update UI jika diperlukan
            });
    };

    document.getElementById('sendRequest').addEventListener('click', handleRequest);
    updateServerUI();
});
