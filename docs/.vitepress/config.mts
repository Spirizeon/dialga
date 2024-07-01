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
      { text: 'Docs', link: '/markdown-examples' },
      { text: 'Source', link: 'https://github.com/spirizeon/dialga' },
    ],
		footer: {
			message: 'Released under the MIT License.',
			copyright: 'Copyright © 2024-present spirizeon',
		},
    sidebar: [
      {
        text: 'Documentation =>',
        items: [
          { text: 'Getting started 🚀', link: '/markdown-examples' },
          { text: 'How to use ✅', link: '/api-examples' }
        ]
      }
    ],

    socialLinks: [
      { icon: 'github', link: 'https://github.com/spirizeon/' },
    ]
  }
})
