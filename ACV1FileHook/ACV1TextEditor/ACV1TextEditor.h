#pragma once
#include <string>
#include <vector>
#include <list>

namespace ACV1
{
	class TextEditor
	{
	private:
		std::wstring m_wsFile;
		std::vector<std::pair<std::size_t, std::wstring>> m_vecRawLine;
		std::vector<std::pair<std::size_t, std::wstring>> m_vecTraLine;

	private:
		bool ReadTransLine();
		bool ReadRawLine(size_t uCodePage);
		bool ReplaceLine(bool isInsertName);
		bool WriteBackLine(size_t uInsCodePage, size_t uRawCodePage);
		size_t FindCharacterName(std::wstring& wsText);

	public:
		TextEditor();
		~TextEditor();

		bool ExtractText(std::wstring& wsFileName, size_t uCodePage);
		bool InsertText(std::wstring& wsFileName, size_t uInsCodePage, size_t uRawCodePage, bool isInsertName);
		bool ListName(std::wstring& wsFileName, std::list<std::wstring>& listName);
		bool FormatLine(std::wstring& wsFileName);
	};
}

