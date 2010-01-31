#ifndef __open_resource_dialog__
#define __open_resource_dialog__

/**
@file
Subclass of OpenResourceDialogBase, which is generated by wxFormBuilder.
*/

#include "openresourcedialogbase.h"
#include <vector>
#include "entry.h"
#include <wx/arrstr.h>

class IManager;

class OpenResourceDialogItemData : public wxClientData
{
public:
	wxString m_file;
	int      m_line;
	wxString m_pattern;
	wxString m_resourceType;
	wxString m_name;
	wxString m_scope;

public:
	OpenResourceDialogItemData() : m_file(wxT("")), m_line(wxNOT_FOUND), m_pattern(wxT("")), m_resourceType(wxT("")), m_name(wxT("")), m_scope(wxT("")) {
	}

	OpenResourceDialogItemData(const wxString &file, int line, const wxString &pattern, const wxString &type, const wxString &name, const wxString &scope)
			: m_file(file)
			, m_line(line)
			, m_pattern(pattern)
			, m_resourceType(type)
			, m_name(name)
			, m_scope(scope) {
	}

	virtual ~OpenResourceDialogItemData() {
	}

	bool IsOk() const;
};

/** Implementing OpenResourceDialogBase */
class OpenResourceDialog : public OpenResourceDialogBase
{
	IManager *                 m_manager;
	wxString                   m_type;
	wxArrayString              m_files;
	std::vector<TagEntryPtr>   m_tags;
	OpenResourceDialogItemData m_selection;

protected:
	void DoPopulateList();
	void DoPopulateWorkspaceFile();
	void DoPopulateTags();
	void DoSelectItem(int selection, bool makeFirst = true);
	void Clear();
	int  DoAppendLine(const wxString &col1, const wxString &col2, const wxString &col3, bool boldFont, OpenResourceDialogItemData *clientData);
	
public:
	static wxString TYPE_WORKSPACE_FILE;
	static wxString TYPE_CLASS;
	static wxString TYPE_MACRO;
	static wxString TYPE_FUNCTION;
	static wxString TYPE_TYPEDEF;
	static wxString TYPE_NAMESPACE;

protected:
	// Handlers for OpenResourceDialogBase events.
	void OnText( wxCommandEvent& event );
	void OnType( wxCommandEvent& event );
	void OnUsePartialMatching( wxCommandEvent& event );
	void OnEnter( wxCommandEvent& event );
	void OnItemActivated( wxListEvent& event );
	void OnKeyDown( wxKeyEvent& event );
	void OnOK( wxCommandEvent& event );
	void OnOKUI( wxUpdateUIEvent& event );
	void OnItemSelected( wxListEvent& event );


public:
	/** Constructor */
	OpenResourceDialog( wxWindow* parent, IManager *manager, const wxString &type, bool allowChangeType = true );
	virtual ~OpenResourceDialog();

	const OpenResourceDialogItemData& GetSelection() const {
		return m_selection;
	}

	/**
	 * \brief helper method for opening the selection
	 * \param selection
	 * \return
	 */
	static void OpenSelection(const OpenResourceDialogItemData &selection, IManager *manager);
};

#endif // __open_resource_dialog__
