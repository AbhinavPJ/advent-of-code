import asyncio
from pyppeteer import launch

YEAR = 2024

async def main():
    browser = await launch(
        headless=True,
        # Use system Chrome instead of downloaded Chromium
        executablePath="/Applications/Google Chrome.app/Contents/MacOS/Google Chrome",
        args=[
            "--no-sandbox",
            "--disable-dev-shm-usage",
            "--disable-gpu",
        ],
        dumpio=True,  # prints browser errors to your terminal if something goes wrong
    )

    page = await browser.newPage()

    for day in range(1, 26):
        url = f"https://adventofcode.com/{YEAR}/day/{day}?print"
        output = f"day{day:02d}.pdf"

        print(f"Opening {url}")
        await page.goto(url, {"waitUntil": "networkidle2"})
        await page.pdf({
            "path": output,
            "format": "A4",
            "printBackground": True,
        })
        print("Saved:", output)

    await browser.close()

if __name__ == "__main__":
    # Python 3.12 way (fixes the deprecation warning)
    asyncio.run(main())
