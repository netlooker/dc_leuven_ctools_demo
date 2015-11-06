<?php
/**
 * @file
 * dc_leuven_ctools_demo.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dc_leuven_ctools_demo_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'app_compare_nodes';
  $page->task = 'page';
  $page->admin_title = 'App | Compare nodes';
  $page->admin_description = 'Page for comparing nodes.';
  $page->path = 'comp/%node1/%node2';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_bundle:node',
        'settings' => array(
          'type' => array(
            'product' => 'product',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'entity_bundle:node',
        'settings' => array(
          'type' => array(
            'product' => 'product',
          ),
        ),
        'context' => 'argument_entity_id:node_2',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'node1' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    'node2' => array(
      'id' => 2,
      'identifier' => 'Node: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_app_compare_nodes__panel';
  $handler->task = 'page';
  $handler->subtask = 'app_compare_nodes';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Product 1 - Stock',
        'keyword' => 'product_1_stock',
        'name' => 'entity_from_field:field_stock_reference-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Product 2 - Stock',
        'keyword' => 'product_2_stock',
        'name' => 'entity_from_field:field_stock_reference-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_2',
        'id' => 2,
      ),
      2 => array(
        'identifier' => 'Stock 1 - Warehouse',
        'keyword' => 'stock_1_warehouse',
        'name' => 'entity_from_field:field_warehouse_reference-node-node',
        'delta' => 0,
        'context' => 'relationship_entity_from_field:field_stock_reference-node-node_1',
        'id' => 1,
      ),
      3 => array(
        'identifier' => 'Stock 2 - Warehouse',
        'keyword' => 'stock_2_warehouse',
        'name' => 'entity_from_field:field_warehouse_reference-node-node',
        'delta' => 0,
        'context' => 'relationship_entity_from_field:field_stock_reference-node-node_2',
        'id' => 2,
      ),
    ),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Compare [%node1:title] VS [%node2:title]';
  $display->uuid = '99c13244-9876-4400-9eb2-39ef762d4958';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1a7d1c39-866f-42c4-8c59-6603921ecfb7';
    $pane->panel = 'left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 1,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1a7d1c39-866f-42c4-8c59-6603921ecfb7';
    $display->content['new-1a7d1c39-866f-42c4-8c59-6603921ecfb7'] = $pane;
    $display->panels['left'][0] = 'new-1a7d1c39-866f-42c4-8c59-6603921ecfb7';
    $pane = new stdClass();
    $pane->pid = 'new-0de91f32-31d2-447d-ba4b-551f398f5cc3';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_product_count';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => '.',
        'prefix_suffix' => 1,
      ),
      'context' => 'relationship_entity_from_field:field_stock_reference-node-node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0de91f32-31d2-447d-ba4b-551f398f5cc3';
    $display->content['new-0de91f32-31d2-447d-ba4b-551f398f5cc3'] = $pane;
    $display->panels['left'][1] = 'new-0de91f32-31d2-447d-ba4b-551f398f5cc3';
    $pane = new stdClass();
    $pane->pid = 'new-93db5aa2-c358-48f6-8fa9-a4329ded2651';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_location';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_entity_from_field:field_warehouse_reference-node-node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '93db5aa2-c358-48f6-8fa9-a4329ded2651';
    $display->content['new-93db5aa2-c358-48f6-8fa9-a4329ded2651'] = $pane;
    $display->panels['left'][2] = 'new-93db5aa2-c358-48f6-8fa9-a4329ded2651';
    $pane = new stdClass();
    $pane->pid = 'new-b59b593b-b72d-499a-b802-420bd22224ef';
    $pane->panel = 'right';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 1,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_2',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b59b593b-b72d-499a-b802-420bd22224ef';
    $display->content['new-b59b593b-b72d-499a-b802-420bd22224ef'] = $pane;
    $display->panels['right'][0] = 'new-b59b593b-b72d-499a-b802-420bd22224ef';
    $pane = new stdClass();
    $pane->pid = 'new-d1a155c9-b161-4dab-86d9-4bba4a2a0f6f';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_product_count';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => '.',
        'prefix_suffix' => 1,
      ),
      'context' => 'relationship_entity_from_field:field_stock_reference-node-node_2',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd1a155c9-b161-4dab-86d9-4bba4a2a0f6f';
    $display->content['new-d1a155c9-b161-4dab-86d9-4bba4a2a0f6f'] = $pane;
    $display->panels['right'][1] = 'new-d1a155c9-b161-4dab-86d9-4bba4a2a0f6f';
    $pane = new stdClass();
    $pane->pid = 'new-c9fb4106-feef-4f5a-a427-4b94f3c06d05';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_location';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_entity_from_field:field_warehouse_reference-node-node_2',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c9fb4106-feef-4f5a-a427-4b94f3c06d05';
    $display->content['new-c9fb4106-feef-4f5a-a427-4b94f3c06d05'] = $pane;
    $display->panels['right'][2] = 'new-c9fb4106-feef-4f5a-a427-4b94f3c06d05';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1a7d1c39-866f-42c4-8c59-6603921ecfb7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['app_compare_nodes'] = $page;

  return $pages;

}
