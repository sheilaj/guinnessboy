<?php
/**
 * @file
 * gb_item.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gb_item_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Collection items';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_beer' => 'field_beer',
    'field_brewery' => 'field_brewery',
    'field_item_type' => 'field_item_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_beer' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_brewery' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_item_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="node/add/item">Add item</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_beer_target_id']['id'] = 'field_beer_target_id';
  $handler->display->display_options['relationships']['field_beer_target_id']['table'] = 'field_data_field_beer';
  $handler->display->display_options['relationships']['field_beer_target_id']['field'] = 'field_beer_target_id';
  $handler->display->display_options['relationships']['field_beer_target_id']['label'] = 'Beer';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_brewery_target_id']['id'] = 'field_brewery_target_id';
  $handler->display->display_options['relationships']['field_brewery_target_id']['table'] = 'field_data_field_brewery';
  $handler->display->display_options['relationships']['field_brewery_target_id']['field'] = 'field_brewery_target_id';
  $handler->display->display_options['relationships']['field_brewery_target_id']['relationship'] = 'field_beer_target_id';
  $handler->display->display_options['relationships']['field_brewery_target_id']['label'] = 'Brewery';
  /* Field: Content: Brewery */
  $handler->display->display_options['fields']['field_brewery']['id'] = 'field_brewery';
  $handler->display->display_options['fields']['field_brewery']['table'] = 'field_data_field_brewery';
  $handler->display->display_options['fields']['field_brewery']['field'] = 'field_brewery';
  $handler->display->display_options['fields']['field_brewery']['relationship'] = 'field_beer_target_id';
  $handler->display->display_options['fields']['field_brewery']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_brewery']['delta_offset'] = '0';
  /* Field: Content: Beer */
  $handler->display->display_options['fields']['field_beer']['id'] = 'field_beer';
  $handler->display->display_options['fields']['field_beer']['table'] = 'field_data_field_beer';
  $handler->display->display_options['fields']['field_beer']['field'] = 'field_beer';
  $handler->display->display_options['fields']['field_beer']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_beer']['delta_offset'] = '0';
  /* Field: Content: Type of item */
  $handler->display->display_options['fields']['field_item_type']['id'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['table'] = 'field_data_field_item_type';
  $handler->display->display_options['fields']['field_item_type']['field'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'View';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'view';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'item' => 'item',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_brewery_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Brewery';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_beer_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Beer';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Type of item (field_item_type) */
  $handler->display->display_options['filters']['field_item_type_tid_1']['id'] = 'field_item_type_tid_1';
  $handler->display->display_options['filters']['field_item_type_tid_1']['table'] = 'field_data_field_item_type';
  $handler->display->display_options['filters']['field_item_type_tid_1']['field'] = 'field_item_type_tid';
  $handler->display->display_options['filters']['field_item_type_tid_1']['value'] = '';
  $handler->display->display_options['filters']['field_item_type_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_item_type_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_item_type_tid_1']['expose']['operator_id'] = 'field_item_type_tid_1_op';
  $handler->display->display_options['filters']['field_item_type_tid_1']['expose']['label'] = 'Type of item';
  $handler->display->display_options['filters']['field_item_type_tid_1']['expose']['operator'] = 'field_item_type_tid_1_op';
  $handler->display->display_options['filters']['field_item_type_tid_1']['expose']['identifier'] = 'field_item_type_tid_1';
  $handler->display->display_options['filters']['field_item_type_tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_item_type_tid_1']['vocabulary'] = 'item_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'items';
  $export['items'] = $view;

  return $export;
}
