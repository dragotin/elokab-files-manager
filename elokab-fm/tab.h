/***************************************************************************
 *   elokab Copyright (C) 2014 AbouZakaria <yahiaui@gmail.com>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef TAB_H
#define TAB_H

#include "pagewidget.h"
#include "myfilesystemmodel.h"
#include <QWidget>


#include "settings.h"
#include "owncloudcfg.h"

#include <QTabWidget>
#include <QMimeData>
#include <QUrl>
#include <QDebug>
#include <QApplication>


/**
 * @brief The Tab class السنة البرنامج
 */
class Tab : public QTabWidget
{
    Q_OBJECT
public:

    /**
          * @brief Tab
          *
          * @param actions
          * @param parent
          */
    explicit Tab(Settings *setting,
                 Actions *actions,
                 const ownCloudCfg& ownCloudCfg,
                 QWidget *parent = nullptr);
    ~Tab();

signals:
    void  largeDirectoryChanged(bool arg);
    //!
    void   urlChanged(const QString &url);
    void  tabAdded(const QString &url);
    //!
    void selectedFoldersFiles(QString);

public slots:

    void updateIcons();

    //!  غلق كل الالسنة
    void closeAll();

    //! اضافة لسان جديد
    void addNewTab( const QString &url=QDir::homePath());

    //! تغيير المسار
    void setUrl(const QString &url=QDir::homePath());

    //! مرشح الفلترة
    void setModelFiltrer(const QString& nf);
    //!

    // called from pagewidget if an item should be opened
    void slotOpenFileItem(QModelIndex index);

private slots:

    //!
    // void setLargeDirectory(const QString &dir);

    //! عرض المصغرات او اخفائها
    void setShowThumbnails(bool arg);


    //! غلق اللسان الحالي
    void closeCurentTab();

    //!
    void oncloseRequested(int index);

    //!
    void currentTabChanged(int index);

    //!
    void setCurTabText(const QString &title);

    //!
    void goForward();

    //!
    void goBack();

    //!
    void goUp();

    //!
    void goHome();

    //!
    void goTrash();

    //!
    void goSearch();

    //!
    void  setViewMode(int);

    //!
    void setHiddenFile(bool visible);

    //!
    void setSorting();

    //!
    void renameFiles();

    //!
    void deleteFiles();

    //!
    void pastFiles();

    //!
    void copyFiles();

    //!
    void cutFiles();

    //!
    void moveFilesToTrash();

    //!
    void selectAll();

    //!
    void slotShowOpenwithDlg();

    //!
    void slotShowProperties();

    void dragDropFiles(bool copy,QString path, QStringList list);

    void slotItemsInserted(const QModelIndex &parent, int first, int last);

private:

    /*!< cmment */
    Settings *mSettings;

    /*!< cmment */
    //
    /*!< cmment */
    Actions *mActions;

    /*!< cmment */
    bool mCute;

    const ownCloudCfg& mOwnCloudCfg;

    /*!< cmment */
    PageWidget *pageWidget;

    /*!< cmment */
    MyFileSystemModel *myModel;
    //    QFileSystemModel *myModel;
    //!
    //!
    QMimeData *mimData;

    //!
    QStringList listDirectory;

    bool mSowTumbnails;

    /**
     * @brief _waitToOpenList list to store files to open that first have to
     * be dehydrated. Once they arrive, they get opened.
     */
    QStringList _waitToOpenList;
};

#endif // TAB_H
