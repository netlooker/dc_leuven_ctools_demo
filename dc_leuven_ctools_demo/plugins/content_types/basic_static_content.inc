<?php
/**
 * @file
 * Basic static content type plugin.
 */

$plugin = array(
  'title' => t('Demo | Basic Static Content'),
  'single' => TRUE,
  'category' => t('DC Leuven Ctools'),
  'render callback' => 'basic_static_content_type_render',
);


/**
 * Show a welcome message.
 */
function basic_static_content_type_render($subtype, $conf, $panel_args, $context) {
  $markup =  array(
    '#type' => 'markup',
    '#markup' => t('Welcome on the Best Drupal Camp in Leuven!'),
    '#prefix' => '<h1 class="welcome">',
    '#suffix' => '</h1>',
  );

  $block = new stdClass();
  $block->content = $markup;
  return $block;
}
