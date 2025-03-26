import requests
from bs4 import BeautifulSoup

def print_grid(url):
    response = requests.get(url)

    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
        
        table = soup.find('table')
        rows = table.find_all('tr')
        data = []

        for row in rows[1:]:
            columns = row.find_all('td')
            x = int(columns[0].get_text(strip=True))
            char = columns[1].get_text(strip=True)
            y = int(columns[2].get_text(strip=True))
            data.append((x, y, char))

        max_x = max([item[0] for item in data])
        max_y = max([item[1] for item in data])

        grid = []
        for _ in range(max_y + 1):
            grid.append([' '] * (max_x + 1))

        for x, y, char in data:
            grid[y][x] = char
        
        for row in grid:
            print(''.join(row))

    else:
        print("Failed to retrieve the document")
