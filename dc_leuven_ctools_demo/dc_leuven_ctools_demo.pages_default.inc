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

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'compare_stuff';
  $page->task = 'page';
  $page->admin_title = 'Compare stuff';
  $page->admin_description = '';
  $page->path = 'compare/%node1/%node2';
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
  $handler->name = 'page_compare_stuff__panel';
  $handler->task = 'page';
  $handler->subtask = 'compare_stuff';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
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
  $display->uuid = '21007513-2d7b-4806-b2af-eb4ec888d1b7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0a09a1b1-50df-40e8-a3dc-cb6d126a8783';
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
    $pane->uuid = '0a09a1b1-50df-40e8-a3dc-cb6d126a8783';
    $display->content['new-0a09a1b1-50df-40e8-a3dc-cb6d126a8783'] = $pane;
    $display->panels['left'][0] = 'new-0a09a1b1-50df-40e8-a3dc-cb6d126a8783';
    $pane = new stdClass();
    $pane->pid = 'new-215a4f88-06a7-40be-bd8b-1466c22df234';
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
      'context' => 'relationship_entity_from_field:field_stock_reference-node-node_1',
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
    $pane->uuid = '215a4f88-06a7-40be-bd8b-1466c22df234';
    $display->content['new-215a4f88-06a7-40be-bd8b-1466c22df234'] = $pane;
    $display->panels['left'][1] = 'new-215a4f88-06a7-40be-bd8b-1466c22df234';
    $pane = new stdClass();
    $pane->pid = 'new-770c778c-b83d-4e3c-a491-d905563c1f01';
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
    $pane->uuid = '770c778c-b83d-4e3c-a491-d905563c1f01';
    $display->content['new-770c778c-b83d-4e3c-a491-d905563c1f01'] = $pane;
    $display->panels['right'][0] = 'new-770c778c-b83d-4e3c-a491-d905563c1f01';
    $pane = new stdClass();
    $pane->pid = 'new-4e5bc917-e368-41bf-95f3-9f136cbb0df7';
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
      'context' => 'relationship_entity_from_field:field_stock_reference-node-node_2',
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
    $pane->uuid = '4e5bc917-e368-41bf-95f3-9f136cbb0df7';
    $display->content['new-4e5bc917-e368-41bf-95f3-9f136cbb0df7'] = $pane;
    $display->panels['right'][1] = 'new-4e5bc917-e368-41bf-95f3-9f136cbb0df7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['compare_stuff'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dc';
  $page->task = 'page';
  $page->admin_title = 'dc';
  $page->admin_description = '';
  $page->path = 'dc';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dc__panel';
  $handler->task = 'page';
  $handler->subtask = 'dc';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Demo | Client Context',
        'keyword' => 'client_context',
        'name' => 'client_context',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e92479a1-df0d-40ad-9f04-5d394b2b1f6d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5d3f3eca-3f57-42c8-a46a-7e45bd345718';
    $pane->panel = 'middle';
    $pane->type = 'basic_static_content';
    $pane->subtype = 'basic_static_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5d3f3eca-3f57-42c8-a46a-7e45bd345718';
    $display->content['new-5d3f3eca-3f57-42c8-a46a-7e45bd345718'] = $pane;
    $display->panels['middle'][0] = 'new-5d3f3eca-3f57-42c8-a46a-7e45bd345718';
    $pane = new stdClass();
    $pane->pid = 'new-24b12b3a-413f-424f-9a22-2096989f062f';
    $pane->panel = 'middle';
    $pane->type = 'client_view';
    $pane->subtype = 'client_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => 'full',
      'context' => 'context_client_context_1',
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
    $pane->uuid = '24b12b3a-413f-424f-9a22-2096989f062f';
    $display->content['new-24b12b3a-413f-424f-9a22-2096989f062f'] = $pane;
    $display->panels['middle'][1] = 'new-24b12b3a-413f-424f-9a22-2096989f062f';
    $pane = new stdClass();
    $pane->pid = 'new-2a45f86c-4f6e-420b-82f2-6cba68baaeb6';
    $pane->panel = 'middle';
    $pane->type = 'client_view';
    $pane->subtype = 'client_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => 'basic',
      'context' => 'context_client_context_1',
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
    $pane->uuid = '2a45f86c-4f6e-420b-82f2-6cba68baaeb6';
    $display->content['new-2a45f86c-4f6e-420b-82f2-6cba68baaeb6'] = $pane;
    $display->panels['middle'][2] = 'new-2a45f86c-4f6e-420b-82f2-6cba68baaeb6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5d3f3eca-3f57-42c8-a46a-7e45bd345718';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dc'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'test';
  $page->task = 'page';
  $page->admin_title = 'test';
  $page->admin_description = 'test';
  $page->path = 'test/';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_test__panel';
  $handler->task = 'page';
  $handler->subtask = 'test';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Demo | Client Context',
        'keyword' => 'client_context',
        'name' => 'client_context',
        'id' => 1,
      ),
    ),
    'relationships' => array(
      0 => array(
        'identifier' => 'Demo | Client Subscription Node',
        'keyword' => 'subscription_node',
        'name' => 'client_subscription_relationship',
        'context' => 'context_client_context_1',
        'id' => 1,
      ),
    ),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'test';
  $display->uuid = 'de4a409c-2f1d-456d-bef9-783305ef4079';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e40e0205-150b-4b59-984d-aa7da16c1284';
    $pane->panel = 'middle';
    $pane->type = 'basic_static_content';
    $pane->subtype = 'basic_static_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e40e0205-150b-4b59-984d-aa7da16c1284';
    $display->content['new-e40e0205-150b-4b59-984d-aa7da16c1284'] = $pane;
    $display->panels['middle'][0] = 'new-e40e0205-150b-4b59-984d-aa7da16c1284';
    $pane = new stdClass();
    $pane->pid = 'new-3c28a11e-7951-4c5b-b49d-0c2f84ca44d1';
    $pane->panel = 'middle';
    $pane->type = 'client_view';
    $pane->subtype = 'client_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => 'basic',
      'context' => 'context_client_context_1',
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
    $pane->uuid = '3c28a11e-7951-4c5b-b49d-0c2f84ca44d1';
    $display->content['new-3c28a11e-7951-4c5b-b49d-0c2f84ca44d1'] = $pane;
    $display->panels['middle'][1] = 'new-3c28a11e-7951-4c5b-b49d-0c2f84ca44d1';
    $pane = new stdClass();
    $pane->pid = 'new-3d506798-f1f7-40d3-9def-6ff25773437f';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'premium_content-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_subscription_reference_target_id' => '%subscription_node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3d506798-f1f7-40d3-9def-6ff25773437f';
    $display->content['new-3d506798-f1f7-40d3-9def-6ff25773437f'] = $pane;
    $display->panels['middle'][2] = 'new-3d506798-f1f7-40d3-9def-6ff25773437f';
    $pane = new stdClass();
    $pane->pid = 'new-a2b6af6e-6b7e-42a0-b0f7-64cbdc458e51';
    $pane->panel = 'middle';
    $pane->type = 'client_view';
    $pane->subtype = 'client_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => 'full',
      'context' => 'context_client_context_1',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'a2b6af6e-6b7e-42a0-b0f7-64cbdc458e51';
    $display->content['new-a2b6af6e-6b7e-42a0-b0f7-64cbdc458e51'] = $pane;
    $display->panels['middle'][3] = 'new-a2b6af6e-6b7e-42a0-b0f7-64cbdc458e51';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['test'] = $page;

  return $pages;

}
