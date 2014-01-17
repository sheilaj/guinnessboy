<?php
/**
 * @file
 * gb_item.features.inc
 */

/**
 * Implements hook_views_api().
 */
function gb_item_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function gb_item_node_info() {
  $items = array(
    'item' => array(
      'name' => t('Collection item'),
      'base' => 'node_content',
      'description' => t('Any item in the collection (glass, bottle, etc.)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
