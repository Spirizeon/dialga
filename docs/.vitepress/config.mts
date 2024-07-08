import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "dialga - built by spirizeon",
  description: "documentation page for dialga: reverse engineered git with improvements",
	base: "/dialga/",

  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: 'Home', link: '/' },
      { text: 'Docs', link: '/docs_02.md' },
      { text: 'Source', link: 'https://github.com/spirizeon/dialga' },
    ],
		footer: {
			message: 'Released under the MIT License.',
			copyright: 'Copyright © 2024-present spirizeon',
		},
    sidebar: [
      {
        text: 'Documentation 📖',
        items: [
          { text: '🚀 Getting started', link: '/docs_01.md' },
          { text: '✅ Usage examples', link: '/docs_02.md' },
          { text: '🤝 Contributing', link: '/docs_03.md' },
          { text: '😉 Contact', link: '/docs_06.md' },
          { text: '👮 License', link: '/docs_07.md' },
        ]
      }
    ],

    socialLinks: [
      { icon: 'github', link: 'https://github.com/spirizeon/' },
    ]
  }
})
