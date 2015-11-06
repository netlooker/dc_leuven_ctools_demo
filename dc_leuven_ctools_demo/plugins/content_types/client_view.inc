<?php
/**
 * @file
 * Content type plugin for Client Info view.
 */

$plugin = array(
  'title' => t('Demo | Client Info View'),
  'single' => TRUE,
  'category' => t('DC Leuven Ctools'),
  'required context' => new ctools_context_required(t('Client Context'), 'client_context'),
  'edit form' => 'client_view_content_type_settings',
  'admin info' => 'client_view_content_type_summary',
  'render callback' => 'client_view_content_type_render',
  'hook theme' => 'client_view_content_type_theme',
);


/**
 * Render the Client Info view.
 */
function client_view_content_type_render($subtype, $conf, $panel_args, $context) {
  $mode = isset($conf['mode']) ? $conf['mode'] : 'full';

  $block = new stdClass();
  $block->title = '';
  $block_vars = array(
    'configuration' => $mode,
    'client_context' => $context->data,
  );
  if ($mode == 'full') {
    $block->content = theme('client_view_full_pane', $block_vars);
  }
  else {
    $block->content = theme('client_view_basic_pane', $block_vars);
  }
  return $block;

}

/**
 * Provides settings form for plugin.
 */
function client_view_content_type_settings($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['mode'] = array(
    '#title' => t('Display Mode'),
    '#type' => 'radios',
    '#options' => array(
      'full' => t('Full'),
      'basic' => t('Basic'),
    ),
    '#default_value' => !empty($conf['mode']) ? $conf['mode'] : '',
  );

  return $form;
}

/**
 * Puts the conf values in correct place on the form_state object for saving.
 */
function client_view_content_type_settings_submit($form, &$form_state) {
  $form_state['conf']['mode'] = $form_state['values']['mode'];
}

function client_view_content_type_summary($subtype, $conf, $contexts = NULL) {
  $block = new stdClass();
  $block->title = isset($conf['mode']) ? $conf['mode'] : t('Full');
  $block->content = array(
    '#markup' => t('No info available.'),
  );

  return $block;
}

function client_view_content_type_theme(&$theme, $plugin) {
  $theme['client_view_full_pane'] = array(
    'vars' => array(
      'configuration' => NULL,
      'client_context' => NULL
    ),
    'path' => $plugin['path'],
    'template' => 'client_view_full_pane',
  );

  $theme['client_view_basic_pane'] = array(
    'vars' => array(
      'configuration' => NULL,
      'client_context' => NULL
    ),
    'path' => $plugin['path'],
    'template' => 'client_view_basic_pane',
  );
}