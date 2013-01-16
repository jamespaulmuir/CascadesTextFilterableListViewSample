import bb.cascades 1.0
import com.jamespaulmuir 1.0

Page {
    titleBar: TitleBar {
        title: "Text Filterable ListView Sample"
    }
    Container {
        TextField {
            id: textFilter
            hintText: "Search States"
            onTextChanging: {
                filter(text);
            }
            function filter(name) {
                statesListModel.filterText = name;
                if (name.length < 1) {
                    statesListModel.clearFilter();
                }
            }
        }
        ListView {
            id: statesListView
            layout: StackListLayout {
                headerMode: ListHeaderMode.Sticky
            }
            dataModel: FilterableGroupDataModel {
                id: statesListModel
                sortingKeys: [
                    "name"
                ]
                filterAttribute: "name"
                grouping: ItemGrouping.ByFirstChar
            }
            listItemComponents: [
                ListItemComponent {
                    type: "listItem"
                    StandardListItem {
                        title: ListItemData.name
                    }
                }
            ]
            onCreationCompleted: {
                var states = [
                    'Alabama',
                    'Alaska',
                    'Arizona',
                    'Arkansas',
                    'California',
                    'Colorado',
                    'Connecticut',
                    'Delaware',
                    'Florida',
                    'Georgia',
                    'Hawaii',
                    'Idaho',
                    'Illinois',
                    'Indiana',
                    'Iowa',
                    'Kansas',
                    'Kentucky',
                    'Louisiana',
                    'Maine',
                    'Maryland',
                    'Massachusetts',
                    'Michigan',
                    'Minnesota',
                    'Mississippi',
                    'Missouri',
                    'Montana',
                    'Nebraska',
                    'Nevada',
                    'New Hampshire',
                    'New Jersey',
                    'New Mexico',
                    'New York',
                    'North Carolina',
                    'North Dakota',
                    'Ohio',
                    'Oklahoma',
                    'Oregon',
                    'Pennsylvania',
                    'Rhode Island',
                    'South Carolina',
                    'South Dakota',
                    'Tennessee',
                    'Texas',
                    'Utah',
                    'Vermont',
                    'Virginia',
                    'Washington',
                    'West Virginia',
                    'Wisconsin',
                    'Wyoming'
                ];
                for (var i = 0; i < states.length; i ++) {
                    statesListModel.insert({
                            name: states[i]
                        });
                }
            }
        }
    }
}
