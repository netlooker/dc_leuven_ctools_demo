<?php
/**
 * @file
 * CTools relationship plugin to create a Subscription node context from a Client context.
 *
 */

/**
 * Plugin definition
 */
$plugin = array(
  'title' => t('Demo | Client Subscription Node'),
  'keyword' => 'subscription_node',
  'description' => t('Client Subscription Node'),
  'required context' => new ctools_context_required(t('Client Context'), 'client_context'),
  'context' => 'client_subscription_relationship_context',
);

/**
 * Return a new context based on an existing context.
 */
function client_subscription_relationship_context($context, $conf) {
  if (!empty($context->data)) {
    $subscription_node = node_load($context->data->subscription_nid);
    return ctools_context_create('node', $subscription_node);
  }

  return ctools_context_create_empty('node', NULL);
}