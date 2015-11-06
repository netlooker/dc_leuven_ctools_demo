<?php
/**
 * @file
 * dc_leuven_ctools_demo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dc_leuven_ctools_demo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dc_leuven_ctools_demo_node_info() {
  $items = array(
    'premium_content' => array(
      'name' => t('Premium content'),
      'base' => 'node_content',
      'description' => t('Content type to store premium content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => t('Content type for storying products.'),
      'has_title' => '1',
      'title_label' => t('Product name'),
      'help' => '',
    ),
    'product_stock' => array(
      'name' => t('Product stock'),
      'base' => 'node_content',
      'description' => t('Content type to store information about amount and location of products.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'subscription' => array(
      'name' => t('Subscription'),
      'base' => 'node_content',
      'description' => t('Content type to store information about subscriptions. '),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'warehouse' => array(
      'name' => t('Warehouse'),
      'base' => 'node_content',
      'description' => t('Content type to store information about warehouses with product stocks.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
