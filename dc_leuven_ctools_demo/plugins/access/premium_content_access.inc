<?php
/**
 * @file
 * CTools access plugin based whether the Client is having access to premium
 * content or not.
 *
 */

/**
 * Describe the plugin.
 */
$plugin = array(
  'title' => t('Demo | Premium Content Access'),
  'description' => t('Determines content access based on subscription.'),
  'required context' => array(
    0 => new ctools_context_required(t('Client Context'), 'client_context'),
    1 => new ctools_context_required(t('Premium Content Node'), 'entity:node'),
  ),
  'callback' => 'client_premium_content_access',
  'summary' => 'client_premium_content_access_summary',
);

/**
 * Provide a summary description based on selected settings.
 */
function client_premium_content_access_summary($conf, $context) {
  return t("Will grant access if Client is having right subscription.");
}

/**
 * Function which will check if user is having access to premium content.
 */
function client_premium_content_access($conf, $context) {
  $client_subscr = $context[0]->data->subscription_nid;
  $premium_node = $context[1]->data;
  $premium_wrapper = entity_metadata_wrapper('node', $premium_node);
  $premium_node_subscr = $premium_wrapper->field_subscription_reference->value()->nid;

  if ($client_subscr == $premium_node_subscr) {
    return TRUE;
  }

  drupal_access_denied();
  drupal_exit();
  return FALSE;
}
